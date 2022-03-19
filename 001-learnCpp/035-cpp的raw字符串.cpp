#include<iostream>

using namespace std;

struct Node {
    string name;
};

Node operator "" _my_udl(char const *s, std::size_t sz) {
    //https://en.cppreference.com/w/cpp/language/user_literal
    //user defined literals,用户自定义字面值，从此一切字面值都交给用户去处理了。
    Node no;
    cout << "size=" << sz << "  " << strlen(s) << endl;
    no.name = string(s);
    return no;
}

int main() {
    string s = R"(
C++已经支持多行字符串了，
这里面可以随意地换行，随意地添加双引号。
{ "a":
100, "b": [1, 2, 3, 4]
这里面随便
)";
    const char *ss = R"(天下大势

为我所控)";
    cout << s << endl;
    cout << ss << endl;

    Node x = "this is my node"_my_udl;
    cout << x.name << endl;
    return 0;
}
