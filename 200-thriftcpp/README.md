thrift 安装：
brew install bison
vcpkg install thrift

安装到的路径：`vcpkg/packages/thrift_x64-osx/tools/thrift`

```plain

    find_package(Thrift CONFIG REQUIRED)
    target_link_libraries(main PRIVATE thrift::thrift thriftz::thriftz thriftnb::thriftnb)

```