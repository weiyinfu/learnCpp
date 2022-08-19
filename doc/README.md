# conan
conan和vcpkg是c++包管理的两个主要应用，vcpkg像pip，没有版本概念，中心化管理。  
conan像maven，项目中只引入一个引用。  
总体来说，还是conan更符合主流依赖管理的设定。  

# conan基本用法
编写conanfile.txt
```plain
[requires]
poco/1.9.4
libiconv/1.16
thrift/0.15.0
openssl/1.1.1l
[generators]
cmake
```

然后创建一个build目录存放conan文件。  
```plain
mkdir build
cd build
conan install ..
```

创建CMakeLists.txt，使用CONAN_LIBS当做链接库。  
```plain
cmake_minimum_required(VERSION 3.21)
project(useConan)

set(CMAKE_CXX_STANDARD 14)
add_definitions("-std=c++11")

include(build/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(useConan main.cpp)
target_link_libraries(useConan ${CONAN_LIBS})

```
# conan 中心
https://conan.io/center

在这个网站上可以搜索可用的包及其版本。  

# conan官网
https://conan.io/

# 一个讲conan的博客系列
https://blog.csdn.net/10km/article/details/123028913


# ndkprofile的conanfile.txt
```plain
include(default)
# 需要修改为你的Android NDK实际安装位置
android_ndk=/Users/bytedance/Library/Android/sdk/ndk-bundle
[settings]
arch=armv8
build_type=Release
compiler=clang
compiler.libcxx=c++_static
compiler.version=11
os=Android
os.api_level=21
[tool_requires]
[options]
[env]
# 定义交叉编译工具链文件
CONAN_CMAKE_TOOLCHAIN_FILE=$android_ndk/build/cmake/android.toolchain.cmake
[conf]
tools.android:ndk_path=$android_ndk
```