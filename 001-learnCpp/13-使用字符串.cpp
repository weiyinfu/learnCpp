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
    return 0;
}