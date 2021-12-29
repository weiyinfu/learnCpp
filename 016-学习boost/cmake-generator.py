import os

template = """
cmake_minimum_required(VERSION 3.21)
project(learnBoost)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED COMPONENTS filesystem)
# add_executable(one ./016-学习boost/001-列出文件夹下所有文件.cpp)
# target_link_libraries(one PRIVATE Boost::boost Boost::filesystem)
# add_executable(two ./016-学习boost/002-文件大小.cpp)
# target_link_libraries(two PRIVATE Boost::boost Boost::filesystem)

"""
a = []
for ind, i in enumerate(os.listdir('.')):
    if not i.endswith('.cpp'):
        continue
    target_name = f"target{ind}"
    a.append(f"""
add_executable({target_name} {i})
target_link_libraries({target_name} PRIVATE Boost::boost Boost::filesystem)   
    """)
template += '\n'.join(a)
print(template)
with open('./CMakeLists.txt', 'w') as f:
    f.write(template)
