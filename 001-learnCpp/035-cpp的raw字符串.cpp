#include<iostream>

using namespace std;

int main() {
    std::string s = R"(
C++已经支持多行字符串了，
这里面可以随意地换行，随意地添加双引号。
{ "a":
100, "b": [1, 2, 3, 4]
这里面随便
)";
    return 0;
}
