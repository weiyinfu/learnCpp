#include<iostream>
#include<nlohmann/json.hpp>

using namespace std;
using namespace nlohmann;
namespace ns {
    // a simple struct to model a person
    struct person {
        std::string name;
        std::string address;
        int age;
    };

    void to_json(json &j, const person &p) {
        j = json{{"name",    p.name},
                 {"address", p.address},
                 {"age",     p.age}};
    }

    void from_json(const json &j, person &p) {
        j.at("name").get_to(p.name);
        j.at("address").get_to(p.address);
        j.at("age").get_to(p.age);
    }
} // namespace ns
void complicatedMethod() {
    //超级复杂的转换方法
    ns::person p = {"Ned Flanders", "744 Evergreen Terrace", 60};
    // convert to JSON: copy each value into the JSON object
    json j;
    j["name"] = p.name;
    j["address"] = p.address;
    j["age"] = p.age;

    // convert from JSON: copy each value from the JSON object
    ns::person pp{
            j["name"].get<std::string>(),
            j["address"].get<std::string>(),
            j["age"].get<int>()
    };
}
/**
 * 一种更通用的方式是使用宏，这个库也提供了宏，但是宏对字段数量有限制。
 * */
int main() {
    ns::person p{"Ned Flanders", "744 Evergreen Terrace", 60};
    json j = p;
    std::cout << j << std::endl;
    auto p2 = j.get<ns::person>();
}