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
    char *ssss = nullptr;
    //s = ssss;//此处会报错
    //s.assign(ssss);//此处也会报错
    cout << s << endl;
    return 0;
}