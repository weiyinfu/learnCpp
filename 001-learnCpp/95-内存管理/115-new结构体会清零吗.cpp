#include <iostream>
#include<cstdlib>

using namespace std;
/*
 * new一个结构体并不会把这个结构体的各个字段清零
 * */
struct User {
    int code;
    double x;
    string name;
};

int main() {
    for (auto i = 0; i < 100; i++) {
        auto u = new User;
        cout << u->code << endl;
        u->code=rand();
        free(u);
    }
    return 0;
}