#pragma once

#include <pybind11/pybind11.h>
#include<iostream>
#include <pybind11/numpy.h>
#include<clusterkit/util/builtin.hpp>

using namespace std;

namespace py = pybind11;
namespace clusterkit {
/*
 * 寻找并查集中某个元素的根结点，C++格式
 * **/
int findRoot(int &x, int *&father) {
    int i = x;
    while (father[i] != i) {
        i = father[i];
    }
    int root = i;
    i = x;
    while (father[i] != i) {
        int temp = father[i];
        father[i] = root;
        i = temp;
    }
    return root;
}

/**
 * 寻找并查集中某个元素的根，python格式
 * */
int findRoot(int &x, py::array_t<int> &father) {
    int *a = (int *) (father.request().ptr);
    int i = x;
    while (a[i] != i) {
        i = a[i];
    }
    int root = i;
    i = x;
    while (a[i] != i) {
        int temp = a[i];
        a[i] = root;
        i = temp;
    }
    return root;
}

/*
 * 压缩并查集数组
 * */
void compressUnionFindArray(py::array_t<int> &father) {
    int *a = (int *) (father.request().ptr);
    for (int i = 0; i < father.size(); i++) {
        if (a[i] == i) {
            continue;
        }
        a[i] = findRoot(i, a);
    }
}

//用于初始化
void unionFindPythonInit(py::module &m) {
    m.def("compress_union_find_array", &compressUnionFindArray,
          "压缩并查集");
    m.def("find_root", py::overload_cast<int &, py::array_t<int> &>(&findRoot), "查找并查集中元素的父节点");
}
}
