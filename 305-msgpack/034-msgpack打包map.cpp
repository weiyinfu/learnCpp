#include <iostream>
#include <map>
#include <msgpack.hpp>
#include<sstream>

using namespace std;

/*
把一个map<string,string>用
k=v的形式打印出来
*/
int main() {
    map<string, string> a = {{"one",   "two"},
                             {"three", "four"}};
    stringstream buf;
    msgpack::pack(buf, a);
    cout << buf.str() << endl;
    msgpack::object_handle handle = msgpack::unpack(buf.str().data(), buf.str().size());
    cout << handle.get() << endl;
    auto obj= handle.get();
    cout << obj.type << endl;  // 7,msgpack的数据类型的ID
    // msgpack的object对象跟cJSON是一样的，都是一个结构体
    for (auto i = 0; i < obj.via.map.size; i++) {
        auto kv = obj.via.map.ptr[i];
        cout << string(kv.key.via.str.ptr, kv.key.via.str.ptr + kv.key.via.str.size)
             << "="
             << string(kv.val.via.str.ptr, kv.val.via.str.ptr + kv.val.via.str.size)
             << endl;
    }
    return 0;
}