cmake_minimum_required(VERSION 3.21)
project(useOpenSsl)

set(CMAKE_CXX_STANDARD 14)

set(OpenSSL_LIBRARIES $ENV{VCPKG_ROOT}/installed/x64-osx/lib)
set(OpenSSL_INCLUDE_DIRS $ENV{VCPKG_ROOT}/installed/x64-osx/include)
#find_package(OpenSSL REQUIRED)
message(info "openssl${OpenSSL_FOUND} libraries:${OpenSSL_LIBRARIES} include_dirs:${OpenSSL_INCLUDE_DIRS}")
include_directories( ${OpenSSL_INCLUDE_DIRS})
link_directories(${OpenSSL_LIBRARIES})
#target_link_libraries(main PRIVATE OpenSSL::SSL OpenSSL::Crypto)
