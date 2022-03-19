#include<iostream>

using namespace std;

int main() {
    string s = "天下大势，为我所控";
    cout << s.size() << endl;//output is 27
//    wstring ss="天下大势为我所控";
    u32string ss = U"天下大势，为我所控";
    cout << ss.size() << endl;
    for (auto i: ss) {
        cout << i << endl;
    }
    cout << ss.c_str() << endl;
    return 0;
}