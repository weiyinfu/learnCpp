#include<nlohmann/json.hpp>
#include<iostream>

using namespace std;
using namespace nlohmann;
struct UserXXX {

};

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