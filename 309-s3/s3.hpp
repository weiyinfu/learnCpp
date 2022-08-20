#pragma once

#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/Bucket.h>
#include <aws/s3/model/GetObjectRequest.h>
#include <aws/s3/model/ListObjectsRequest.h>
#include <aws/s3/model/Object.h>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/assert.hpp>
#include <aws/core/utils/logging/DefaultLogSystem.h>
#include <aws/core/utils/logging/AWSLogging.h>
#include <fstream>
#include <clusterkit/util/log.hpp>
#include <iostream>
#include <clusterkit/util/common.hpp>
#include <istream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
namespace clusterkit {

namespace s3 {
inline pair <string, string> splitS3Path(const string &s3Path) {
    //把s3path split成bucket+key的形式
    const string prefix = "s3://";
    BOOST_ASSERT_MSG(boost::starts_with(s3Path, prefix), "s3path not exists");
    int pos = s3Path.find_first_of('/', prefix.length());
    BOOST_ASSERT_MSG(pos < s3Path.length(), "/ not exists in s3Path");
    auto first = s3Path.substr(prefix.length(), pos - prefix.length());
    auto second = s3Path.substr(pos, s3Path.length() - pos);
    auto bucketKey = make_pair(first, second);
    return bucketKey;
}

inline string pathJoin(vector <string> pathList) {
    std::ostringstream o;
    if (boost::ends_with(pathList[0], "/")) {
        o << pathList[0].substr(0, pathList[0].length() - 1);
    } else {
        o << pathList[0];
    }
    for (auto i = 1uL; i < pathList.size(); i++) {
        int beg = 0, end = pathList[i].length();
        if (boost::starts_with(pathList[i], "/")) {
            beg = 1;
        }
        if (boost::ends_with(pathList[i], "/")) {
            end--;
        }
        o << '/' << pathList[i].substr(beg, end);
    }
    return o.str();
}

inline bool isS3Path(const string &s3Path) {
    return boost::starts_with(s3Path, "s3://");
}
};  // namespace s3
class S3Client {
private:
  Aws::SDKOptions options;
  Aws::S3::S3Client *client;
  const string endpointUrl;
public:
  explicit S3Client(const string &endpointUrl) : endpointUrl(endpointUrl) {
      Aws::Utils::Logging::InitializeAWSLogging(
              Aws::MakeShared<Aws::Utils::Logging::DefaultLogSystem>(
                      "RunUnitTests", Aws::Utils::Logging::LogLevel::Trace, "aws_sdk_"));
      Aws::InitAPI(options);
      Aws::Client::ClientConfiguration config;
      config.endpointOverride = endpointUrl;
      this->client = new Aws::S3::S3Client(
              config, Aws::Client::AWSAuthV4Signer::PayloadSigningPolicy::Never,
              false);
  }

  ~S3Client() {
      LOG(trace) << "deleting client of " << endpointUrl;
      delete this->client;
      Aws::ShutdownAPI(options);
  }

  //列出一个站点下的全部桶
  Aws::Vector<Aws::S3::Model::Bucket> listBucketsAmply() {
      auto outcome = client->ListBuckets();
      if (!outcome.IsSuccess()) {
          std::cout << "ListBuckets error: "
                    << outcome.GetError().GetExceptionName() << " - "
                    << outcome.GetError().GetMessage() << std::endl;
          assert(false);//"list buckets error"
      }

      Aws::Vector<Aws::S3::Model::Bucket> bucketList =
              outcome.GetResult().GetBuckets();
      return bucketList;
  }

  vector <string> listBuckets() {
      auto bucketList = listBucketsAmply();
      vector<string> bucketNames(bucketList.size());
      for (const auto &bucket : bucketList) {
          bucketNames.emplace_back(bucket.GetName());
      }
      return bucketNames;
  }

  //列出一个文件夹下的全部文件
  Aws::Vector<Aws::S3::Model::Object> listObjectsAmply(const string &s3Path,
                                                       bool single) {
      auto pathInfo = s3::splitS3Path(s3Path);
      auto bucketName = pathInfo.first, prefix = pathInfo.second;
      Aws::S3::Model::ListObjectsRequest req;
      req.SetBucket(bucketName.c_str());
      req.SetPrefix(prefix.c_str());
      if (single) {
          char delimiter[] = "/";
          req.SetDelimiter(delimiter);
      }
      auto list_objects_outcome = client->ListObjects(req);

      if (!list_objects_outcome.IsSuccess()) {
          LOG(error) << "ListObjects error: "
                     << list_objects_outcome.GetError().GetExceptionName() << " "
                     << list_objects_outcome.GetError().GetMessage() << std::endl;
          assert(false);//list objects error!
      }
      std::cout << "success" << std::endl;
      Aws::Vector<Aws::S3::Model::Object> objectList =
              list_objects_outcome.GetResult().GetContents();
      return objectList;
  }

  vector <string> listObjects(const string &s3Path) {
      auto objectList = listObjectsAmply(s3Path, true);
      vector<string> objectNames(objectList.size());
      for (const auto &obj : objectList) {
          objectNames.emplace_back(obj.GetKey());
      }
      return objectNames;
  }

  Aws::S3::Model::GetObjectResult getObjectAmply(const string &s3Path,
                                                 const string &rangeString = "") {
      Aws::S3::Model::GetObjectRequest getObjectRequest;
      auto pathInfo = s3::splitS3Path(s3Path);
      string bucketName = pathInfo.first;
      string keyName = pathInfo.second;
      getObjectRequest.SetBucket(bucketName.c_str());
      getObjectRequest.SetKey(keyName.c_str());

      if (rangeString.length() > 0) {
          if (!boost::starts_with(rangeString, "bytes=")) {
              std::cout << "rangeString error:" << rangeString << std::endl;
              assert(false);// "rangeString error");
          }
          getObjectRequest.SetRange(rangeString.c_str());
      }
      // Get the object
      Aws::S3::Model::GetObjectOutcome getObjectOutcome =
              this->client->GetObject(getObjectRequest);

      if (!getObjectOutcome.IsSuccess()) {
          const auto &error = getObjectOutcome.GetError();
          std::cout << "ERROR: " << error.GetExceptionName() << ": "
                    << error.GetMessage() << std::endl;
          assert(false);//, "getObjectError");
      }
      // Get an Aws::IOStream reference to the retrieved file
      Aws::S3::Model::GetObjectResult res =
              getObjectOutcome.GetResultWithOwnership();

      return res;
  }

  std::string getObjectContent(const string &s3Path) {
      auto res = getObjectAmply(s3Path);
      Aws::IOStream &body = res.GetBody();
      std::ostringstream o;
      o << body.rdbuf();
      return o.str();
  }
};
};