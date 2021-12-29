cmake_minimum_required(VERSION 3.21)
project(usehttplib)

set(CMAKE_CXX_STANDARD 14)

add_executable(usehttplib server.cpp)

add_executable(myClient cli.cpp)
find_path(CPP_HTTPLIB_INCLUDE_DIRS "httplib.h")
target_include_directories(usehttplib PRIVATE ${CPP_HTTPLIB_INCLUDE_DIRS})
target_include_directories(myClient PRIVATE ${CPP_HTTPLIB_INCLUDE_DIRS})
