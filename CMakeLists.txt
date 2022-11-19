cmake_minimum_required(VERSION 3.21)
project(learnCpp)

set(CMAKE_CXX_STANDARD 14)
set(CONAN_DISABLE_CHECK_COMPILER 1)
include(build/conanbuildinfo.cmake)
conan_basic_setup()
include(gen.cmake)


add_executable(protobuf_v2 150-protobuf/01-protobuf和json.cpp 150-protobuf/gen/haha.pb.cc)
target_link_libraries(protobuf_v2  ${CONAN_LIBS})

add_executable(protobuf_v3 150-protobuf/02-protobuf的optional的默认值.cpp 150-protobuf/gen/haha.pb.cc)
target_link_libraries(protobuf_v3  ${CONAN_LIBS})