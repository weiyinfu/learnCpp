
cmake_minimum_required(VERSION 3.21)
project(learnBoost)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED COMPONENTS filesystem)
# add_executable(one ./016-学习boost/001-列出文件夹下所有文件.cpp)
# target_link_libraries(one PRIVATE Boost::boost Boost::filesystem)
# add_executable(two ./016-学习boost/002-文件大小.cpp)
# target_link_libraries(two PRIVATE Boost::boost Boost::filesystem)


add_executable(target0 009-类型转换.cpp)
target_link_libraries(target0 PRIVATE Boost::boost Boost::filesystem)   
    

add_executable(target2 006-boost的format.cpp)
target_link_libraries(target2 PRIVATE Boost::boost Boost::filesystem)   
    

add_executable(target3 022-thread-local.cpp)
target_link_libraries(target3 PRIVATE Boost::boost Boost::filesystem)   
    

add_executable(target4 028-使用boost.json.cpp)
target_link_libraries(target4 PRIVATE Boost::boost Boost::filesystem)   
    

add_executable(target5 020-使用boost.bind.cpp)
target_link_libraries(target5 PRIVATE Boost::boost Boost::filesystem)   
    

add_executable(target6 015-使用括号函数定义多线程.cpp)
target_link_libraries(target6 PRIVATE Boost::boost Boost::filesystem)   
    

add_executable(target7 002-文件大小.cpp)
target_link_libraries(target7 PRIVATE Boost::boost Boost::filesystem)   
    

add_executable(target8 003-first.cpp)
target_link_libraries(target8 PRIVATE Boost::boost Boost::filesystem)   
    

add_executable(target9 001-列出文件夹下所有文件.cpp)
target_link_libraries(target9 PRIVATE Boost::boost Boost::filesystem)   
    

add_executable(target11 011-线程.cpp)
target_link_libraries(target11 PRIVATE Boost::boost Boost::filesystem)   
    

add_executable(target12 005-使用path.cpp)
target_link_libraries(target12 PRIVATE Boost::boost Boost::filesystem)   
    

add_executable(target13 004-listdir.cpp)
target_link_libraries(target13 PRIVATE Boost::boost Boost::filesystem)   
    