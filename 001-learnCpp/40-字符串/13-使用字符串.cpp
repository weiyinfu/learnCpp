#include <string>
#include <iostream>
#include<sstream>

using namespace std;

int main() {
    string s = "xxx";
    cout << s.length() << endl;
    stringstream x;
    x << 1 << endl << 2 << "hello world";
    cout << x.str() << endl;

    char *ss = nullptr;
    printf("%s\n", ss);
    //会crash
    try {
        cout << "test " << std::stoull("test") << endl;
    } catch (std::invalid_argument &e) {
        cout << e.what() << endl;
    }
    cout << "test " << std::stoull("  0  ") << endl;

    string sss = nullptr;
    cout << sss.size() << "  sss.size()   " << (sss == "") << endl;
    return 0;
}