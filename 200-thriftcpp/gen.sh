echo $VCPKG_ROOT
${VCPKG_ROOT}/packages/thrift_x64-osx/tools/thrift/thrift -r --gen cpp main.thrift
${VCPKG_ROOT}/packages/thrift_x64-osx/tools/thrift/thrift -r --gen json main.thrift
${VCPKG_ROOT}/packages/thrift_x64-osx/tools/thrift/thrift -r --gen markdown main.thrift
${VCPKG_ROOT}/packages/thrift_x64-osx/tools/thrift/thrift -r --gen html main.thrift
${VCPKG_ROOT}/packages/thrift_x64-osx/tools/thrift/thrift -r --gen go main.thrift
${VCPKG_ROOT}/packages/thrift_x64-osx/tools/thrift/thrift -r --gen netstd main.thrift