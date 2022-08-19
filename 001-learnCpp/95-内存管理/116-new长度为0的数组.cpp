#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "";
    char *ss = new char[s.size()]{0};//报错：badalloc
    char *sss = new char[s.size()];//不报错，返回一个空数组
    cout << "new over" << endl;
    cout << strlen(ss) << endl;
    return 0;
}