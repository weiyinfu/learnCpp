#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <iostream>
#include <sstream>

void test2() {
    std::string s = "{ \"a\": { \"b\":1, \"c\":2 }, \"d\":3 }";
    std::stringstream ss(s);
    boost::property_tree::ptree ptree;
    boost::property_tree::read_json(ss, ptree);
    std::cout << "input text:" << std::endl;
    boost::property_tree::write_json(std::cout, ptree);
    std::cout << "-------------------------" << std::endl;
    std::cout << "parse result: " << std::endl;
    std::cout << "a->b: " << ptree.get<int>("a.b") << std::endl;
    std::cout << "a->c: " << ptree.get<int>("a.c") << std::endl;
    std::cout << "d: " << ptree.get<int>("d") << std::endl;
}

void test1() {
    std::string s = R"({ "a": 100, "b": [1, 2, 3, 4] })";
    std::stringstream ss(s);
    boost::property_tree::ptree ptree;
    // 读取JSON数据
    boost::property_tree::read_json(ss, ptree);
    boost::property_tree::ptree son = ptree.get_child("a");
    using namespace std;

    std::cout << son.data() << std::endl;
    // 写回JSON数据
    boost::property_tree::write_json("./tmp.json", ptree);
}

int main() {}
