#include<json/json.hpp>
#include<iostream>

using namespace std;
using namespace nlohmann;
struct User {

};

void basicUse() {
    json x = {};
    cout << x.dump() << endl;
    x = {0, 1, 2};
    cout << x.dump() << endl;
    x = {"one", "two", 3};
    cout << x.dump() << endl;
    cout << x[0].get<string>() << endl;
    cout << x[2].get<int>() << endl;
    json y;
    cout << y.dump() << endl;
    x = {134l};
    cout << x.dump() << endl;
    const char *s = "hello";
    x = s;
    cout << x.dump() << endl;
    auto userHandle = new User;
    x = {(uint64_t) userHandle};
    cout << x.dump() << endl;
}

int main() {
    json a;
    a["one"] = 1;
    a["two"] = 2;
    cout << a.dump() << endl;
    cout << a["three"] << endl;
    //报错，必须先判断是否为空
//    cout << a["three"].get<string>() << endl;
    a = nullptr;
    cout << a.is_null() << a.empty() << endl;
    a = vector<int>();
    cout << a.is_null() << a.empty() << endl;
    a = map<int, int>();
    cout << a.is_null() << a.empty() << endl;
    a = "";
    cout << a.is_null() << a.empty() << endl;
    return 0;
}