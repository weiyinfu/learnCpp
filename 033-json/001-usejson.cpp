#include <iostream>
#include<nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

int main() {
    const char *s = nullptr;
    //此处空指针直接崩掉
    json a = {{"one", 1},
              {"two", 2},
              "three", s};
    cout << a.dump() << endl;
    //如何制定json的类型
    json json_array(json::array());
    json json_map(json::object());
    json x(json::number_integer_t);
    cout << json_array << endl;
    cout << json_map << endl;
    cout << x << endl;
    return 0;
}