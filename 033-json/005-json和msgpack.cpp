#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using namespace nlohmann;

/*
 * msgpack是一种协议，nlohmann这个人实现了bson、msgpack等各种协议，使得json可以和各种数据格式进行转换。
 * */
int main() {
    json x;
    x["name"] = "weiyinfu";
    long long age = 1 << 34;
    x["age"] = age;
    cout << x << endl;
    auto buffer = json::to_msgpack(x);//vector<uint8_t>
    auto res = json::from_msgpack(buffer);
    cout << res << endl;
    return 0;
}