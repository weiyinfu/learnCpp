#include <msgpack.hpp>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;


struct Foo {
    int i;
    string str;
    // 原始指针类型，内部封装了pack_raw和pack_raw_body方法
    msgpack::type::raw_ref data;

    MSGPACK_DEFINE (i, str, data);
};


int main(int argc, char **argv) {
    Foo f;
    f.i = 4;
    f.str = "hello world";
    const char *tmp = "msgpack";
    f.data.ptr = tmp;
    f.data.size = strlen(tmp) + 1;

    msgpack::sbuffer sbuf;
    msgpack::pack(sbuf, f);

    msgpack::unpacked unpack;
    msgpack::unpack(&unpack, sbuf.data(), sbuf.size());

    msgpack::object obj = unpack.get();

    Foo f2;
    obj.convert(&f2);

    cout << f2.i << ", " << f2.str << ", ";
    cout << f2.data.ptr << endl;

    return 0;
}