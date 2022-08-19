#include<iostream>
#include <mutex>
#include <thread>

using namespace std;
once_flag flag;

void f(int a, int b, int c) {
    cout << a << b << c << endl;
}

int main() {
    for (int i = 0; i < 10; i++)
        call_once(flag, f, 1, 2, 3);
    return 0;
}