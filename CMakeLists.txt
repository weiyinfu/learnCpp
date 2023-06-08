cmake_minimum_required(VERSION 3.21)
project(learnCpp)

set(CMAKE_CXX_STANDARD 14)
set(CONAN_DISABLE_CHECK_COMPILER 1)
include(build/conanbuildinfo.cmake)
conan_basic_setup()
include(gen.cmake)