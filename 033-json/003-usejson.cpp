#include<nlohmann/json.hpp>
#include<iostream>

using namespace std;
using namespace nlohmann;
struct UserXXX {

};

int main() {
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
    auto userHandle = new UserXXX;
    x = {(uint64_t) userHandle};
    cout << x.dump() << endl;
}