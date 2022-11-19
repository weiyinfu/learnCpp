#include <iostream>
#include<toml11/toml.hpp>

using namespace std;

/*
 * https://github.com/ToruNiina/toml11
 * */
int main() {
    cout << "hello" << endl;
    auto data = toml::parse("/Users/bytedance/Desktop/Github/learnCpp/307-toml/config.toml");
    auto general = toml::find(data, "general");
    auto language = toml::find(general, "language");
    cout << "language:" << language << endl;
    auto launchDetail = toml::find(data, "launch_detail");
    cout << "launchDetail" << launchDetail << endl;
    return 0;
}