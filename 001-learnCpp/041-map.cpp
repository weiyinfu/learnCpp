#include<iostream>
#include<map>
#include<list>

using namespace std;

int main() {
    map<string, string> a = {
            {"one", "1"},
            {"two", "2"},
            {"one", "3"}
    };
    cout << "four:" << a.find("four")->second.c_str() << endl;
    return 0;
}