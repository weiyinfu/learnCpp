使用Python生成CMakeLists的方式是开发多入口程序的好方法。  

# C++教程
* 菜鸟网：https://www.runoob.com/cplusplus/cpp-tutorial.html
* cppreference:
https://zh.cppreference.com/w/
* C语言中文网：http://c.biancheng.net/cpp/biancheng/cpp/rumen_1/
* 微软文档：
  * https://docs.microsoft.com/zh-cn/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-170
  * https://docs.microsoft.com/zh-cn/cpp/c-language/c-language-reference?view=msvc-170
* learn Cpp:一个英文教程，https://www.learncpp.com/cpp-tutorial/introduction-to-these-tutorials/
* awesome cpp：https://github.com/fffaraz/awesome-cpp

# C++ HTTP
使用C++实现server和client。  
`vcpkg install cpp-httplib`
https://github.com/yhirose/cpp-httplib  

# C++与python交互相关资料
https://github.com/weiyinfu/learnCython
https://github.com/weiyinfu/learnCtypes


# 常用库
* SPTAG
* pybind11
* aws-sdk
* boost
* boost-log
* boost-process
* cjson
* eigen
* json
* msgpack
* numcpp
* opencv
* pybind11

# 注意
本项目使用conan1.x构建，使用2.x构建会报错。  
pip install conan==1.59.0


conan install .. --build=boost --build=msgpack --build=poco

conan install openssl/1.1.1a@ --build missing


thrift/0.15.0
protobuf/3.13.0
msgpack/3.3.0

conan profile detect 如果家目录下没有~/.conan2执行这个命令。  

# conan2.0文档
https://docs.conan.io/2/installation.html

# 常用命令
```
在learnCpp目录下：conan install . --output-folder=build --build=missing
在build目录下：cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake  --build .
```