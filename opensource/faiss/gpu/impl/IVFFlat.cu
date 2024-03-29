/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include "IVFFlat.cuh"
#include "../GpuResources.h"
#include "FlatIndex.cuh"
#include "InvertedListAppend.cuh"
#include "IVFFlatScan.cuh"
#include "RemapIndices.h"
#include "../utils/CopyUtils.cuh"
#include "../utils/DeviceDefs.cuh"
#include "../utils/DeviceUtils.h"
#include "../utils/Float16.cuh"
#include "../utils/HostTensor.cuh"
#include "../utils/Transpose.cuh"
#include <limits>
#include <thrust/host_vector.h>
#include <unordered_map>

namespace faiss { namespace gpu {

IVFFlat::IVFFlat(GpuResources* resources,
                 FlatIndex* quantizer,
                 bool l2Distance,
                 bool useFloat16,
                 IndicesOptions indicesOptions,
                 MemorySpace space) :
    IVFBase(resources,
            quantizer,
#ifdef FAISS_USE_FLOAT16
            useFloat16 ?
            sizeof(half) * quantizer->getDim()
            : sizeof(float) * quantizer->getDim(),
#else
            sizeof(float) * quantizer->getDim(),
#endif
            indicesOptions,
            space),
    l2Distance_(l2Distance),
    useFloat16_(useFloat16) {
}

IVFFlat::~IVFFlat() {
}

void
IVFFlat::addCodeVectorsFromCpu(int listId,
                               const float* vecs,
                               const long* indices,
                               size_t numVecs) {
  // This list must already exist
  FAISS_ASSERT(listId < deviceListData_.size());
  auto stream = resources_->getDefaultStreamCurrentDevice();

  // If there's nothing to add, then there's nothing we have to do
  if (numVecs == 0) {
    return;
  }

  size_t lengthInBytes = numVecs * bytesPerVector_;

  auto& listData = deviceListData_[listId];
  auto prevData = listData->data();

  // We only have int32 length representations on the GPU per each
  // list; the length is in sizeof(char)
  FAISS_ASSERT(listData->size() + lengthInBytes <=
         (size_t) std::numeric_limits<int>::max());

  if (useFloat16_) {
#ifdef FAISS_USE_FLOAT16
    // We have to convert data to the half format.
    // Make sure the source data is on our device first; it is not
    // guaranteed before function entry to avoid unnecessary h2d copies
    auto floatData =
      toDevice<float, 1>(resources_,
                         getCurrentDevice(),
                         (float*) vecs,
                         stream,
                         {(int) numVecs * dim_});
    auto halfData = toHalf<1>(resources_, stream, floatData);

    listData->append((unsigned char*) halfData.data(),
                     lengthInBytes,
                     stream,
                     true /* exact reserved size */);
#else
    // we are not compiling with float16 support
    FAISS_ASSERT(false);
#endif
  } else {
    listData->append((unsigned char*) vecs,
                     lengthInBytes,
                     stream,
                     true /* exact reserved size */);
  }

  // Handle the indices as well
  addIndicesFromCpu_(listId, indices, numVecs);

  // This list address may have changed due to vector resizing, but
  // only bother updating it on the device if it has changed
  if (prevData != listData->data()) {
    deviceListDataPointers_[listId] = listData->data();
  }

  // And our size has changed too
  int listLength = listData->size() / bytesPerVector_;
  deviceListLengths_[listId] = listLength;

  // We update this as well, since the multi-pass algorithm uses it
  maxListLength_ = std::max(maxListLength_, listLength);

  // device_vector add is potentially happening on a different stream
  // than our default stream
  if (stream != 0) {
    streamWait({stream}, {0});
  }
}

int
IVFFlat::classifyAndAddVectors(Tensor<float, 2, true>& vecs,
                               Tensor<long, 1, true>& indices) {
  FAISS_ASSERT(vecs.getSize(0) == indices.getSize(0));
  FAISS_ASSERT(vecs.getSize(1) == dim_);

  auto& mem = resources_->getMemoryManagerCurrentDevice();
  auto stream = resources_->getDefaultStreamCurrentDevice();

  // Number of valid vectors that we actually add; we return this
  int numAdded = 0;

  // We don't actually need this
  DeviceTensor<float, 2, true> listDistance(mem, {vecs.getSize(0), 1}, stream);
  // We use this
  DeviceTensor<int, 2, true> listIds2d(mem, {vecs.getSize(0), 1},  stream);
  auto listIds = listIds2d.view<1>({vecs.getSize(0)});

  quantizer_->query(vecs, 1, listDistance, listIds2d, false);

  // Copy the lists that we wish to append to back to the CPU
  // FIXME: really this can be into pinned memory and a true async
  // copy on a different stream; we can start the copy early, but it's
  // tiny
  HostTensor<int, 1, true> listIdsHost(listIds, stream);

  // Now we add the encoded vectors to the individual lists
  // First, make sure that there is space available for adding the new
  // encoded vectors and indices

  // list id -> # being added
  std::unordered_map<int, int> assignCounts;

  // vector id -> offset in list
  // (we already have vector id -> list id in listIds)
  HostTensor<int, 1, true> listOffsetHost({listIdsHost.getSize(0)});

  for (int i = 0; i < listIds.getSize(0); ++i) {
    int listId = listIdsHost[i];

    // Add vector could be invalid (contains NaNs etc)
    if (listId < 0) {
      listOffsetHost[i] = -1;
      continue;
    }

    FAISS_ASSERT(listId < numLists_);
    ++numAdded;

    int offset = deviceListData_[listId]->size() / bytesPerVector_;

    auto it = assignCounts.find(listId);
    if (it != assignCounts.end()) {
      offset += it->second;
      it->second++;
    } else {
      assignCounts[listId] = 1;
    }

    listOffsetHost[i] = offset;
  }

  // If we didn't add anything (all invalid vectors), no need to
  // continue
  if (numAdded == 0) {
    return 0;
  }

  // We need to resize the data structures for the inverted lists on
  // the GPUs, which means that they might need reallocation, which
  // means that their base address may change. Figure out the new base
  // addresses, and update those in a batch on the device
  {
    for (auto& counts : assignCounts) {
      auto& data = deviceListData_[counts.first];
      data->resize(data->size() + counts.second * bytesPerVector_,
                   stream);
      int newNumVecs = (int) (data->size() / bytesPerVector_);

      auto& indices = deviceListIndices_[counts.first];
      if ((indicesOptions_ == INDICES_32_BIT) ||
          (indicesOptions_ == INDICES_64_BIT)) {
        size_t indexSize =
          (indicesOptions_ == INDICES_32_BIT) ? sizeof(int) : sizeof(long);

        indices->resize(indices->size() + counts.second * indexSize, stream);
      } else if (indicesOptions_ == INDICES_CPU) {
        // indices are stored on the CPU side
        FAISS_ASSERT(counts.first < listOffsetToUserIndex_.size());

        auto& userIndices = listOffsetToUserIndex_[counts.first];
        userIndices.resize(newNumVecs);
      } else {
        // indices are not stored on the GPU or CPU side
        FAISS_ASSERT(indicesOptions_ == INDICES_IVF);
      }

      // This is used by the multi-pass query to decide how much scratch
      // space to allocate for intermediate results
      maxListLength_ = std::max(maxListLength_, newNumVecs);
    }

    // Update all pointers to the lists on the device that may have
    // changed
    {
      std::vector<int> listIds(assignCounts.size());
      int i = 0;
      for (auto& counts : assignCounts) {
        listIds[i++] = counts.first;
      }

      updateDeviceListInfo_(listIds, stream);
    }
  }

  // If we're maintaining the indices on the CPU side, update our
  // map. We already resized our map above.
  if (indicesOptions_ == INDICES_CPU) {
    // We need to maintain the indices on the CPU side
    HostTensor<long, 1, true> hostIndices(indices, stream);

    for (int i = 0; i < hostIndices.getSize(0); ++i) {
      int listId = listIdsHost[i];

      // Add vector could be invalid (contains NaNs etc)
      if (listId < 0) {
        continue;
      }

      int offset = listOffsetHost[i];

      FAISS_ASSERT(listId < listOffsetToUserIndex_.size());
      auto& userIndices = listOffsetToUserIndex_[listId];

      FAISS_ASSERT(offset < userIndices.size());
      userIndices[offset] = hostIndices[i];
    }
  }

  // We similarly need to actually append the new vectors
  {
    DeviceTensor<int, 1, true> listOffset(mem, listOffsetHost, stream);

    // Now, for each list to which a vector is being assigned, write it
    runIVFFlatInvertedListAppend(listIds,
                                 listOffset,
                                 vecs,
                                 indices,
                                 useFloat16_,
                                 deviceListDataPointers_,
                                 deviceListIndexPointers_,
                                 indicesOptions_,
                                 stream);
  }

  return numAdded;
}

void
IVFFlat::query(Tensor<float, 2, true>& queries,
               int nprobe,
               int k,
               Tensor<float, 2, true>& outDistances,
               Tensor<long, 2, true>& outIndices) {
  auto& mem = resources_->getMemoryManagerCurrentDevice();
  auto stream = resources_->getDefaultStreamCurrentDevice();

  // These are caught at a higher level
  FAISS_ASSERT(nprobe <= GPU_MAX_SELECTION_K);
  FAISS_ASSERT(k <= GPU_MAX_SELECTION_K);
  nprobe = std::min(nprobe, quantizer_->getSize());

  FAISS_ASSERT(queries.getSize(1) == dim_);

  FAISS_ASSERT(outDistances.getSize(0) == queries.getSize(0));
  FAISS_ASSERT(outIndices.getSize(0) == queries.getSize(0));

  // Reserve space for the quantized information
  DeviceTensor<float, 2, true>
    coarseDistances(mem, {queries.getSize(0), nprobe}, stream);
  DeviceTensor<int, 2, true>
    coarseIndices(mem, {queries.getSize(0), nprobe}, stream);

  // Find the `nprobe` closest lists; we can use int indices both
  // internally and externally
  quantizer_->query(queries,
                    nprobe,
                    coarseDistances,
                    coarseIndices,
                    false);

  runIVFFlatScan(queries,
                 coarseIndices,
                 deviceListDataPointers_,
                 deviceListIndexPointers_,
                 indicesOptions_,
                 deviceListLengths_,
                 maxListLength_,
                 k,
                 l2Distance_,
                 useFloat16_,
                 outDistances,
                 outIndices,
                 resources_);

  // If the GPU isn't storing indices (they are on the CPU side), we
  // need to perform the re-mapping here
  // FIXME: we might ultimately be calling this function with inputs
  // from the CPU, these are unnecessary copies
  if (indicesOptions_ == INDICES_CPU) {
    HostTensor<long, 2, true> hostOutIndices(outIndices, stream);

    ivfOffsetToUserIndex(hostOutIndices.data(),
                         numLists_,
                         hostOutIndices.getSize(0),
                         hostOutIndices.getSize(1),
                         listOffsetToUserIndex_);

    // Copy back to GPU, since the input to this function is on the
    // GPU
    outIndices.copyFrom(hostOutIndices, stream);
  }
}

std::vector<float>
IVFFlat::getListVectors(int listId) const {
  FAISS_ASSERT(listId < deviceListData_.size());
  auto& encVecs = *deviceListData_[listId];

  auto stream = resources_->getDefaultStreamCurrentDevice();

  if (useFloat16_) {
#ifdef FAISS_USE_FLOAT16
    size_t num = encVecs.size() / sizeof(half);

    Tensor<half, 1, true> devHalf((half*) encVecs.data(), {(int) num});
    auto devFloat = fromHalf(resources_, stream, devHalf);

    std::vector<float> out(num);
    HostTensor<float, 1, true> hostFloat(out.data(), {(int) num});
    hostFloat.copyFrom(devFloat, stream);

    return out;
#endif
  }

  size_t num = encVecs.size() / sizeof(float);

  Tensor<float, 1, true> devFloat((float*) encVecs.data(), {(int) num});

  std::vector<float> out(num);
  HostTensor<float, 1, true> hostFloat(out.data(), {(int) num});
  hostFloat.copyFrom(devFloat, stream);

  return out;
}

} } // namespace
