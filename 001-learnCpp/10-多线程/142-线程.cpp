#include <thread>
#include <iostream>
#include <atomic>

using namespace std;
volatile int x = 0;
int xx = 0;
atomic_int xxx(0);
/**
 * 切记：
 * C++中的volatile跟Java中的volatile不一样
 * C++中的volatile不是线程安全的，不能妄图通过它来实现线程安全
 * C++中要想实现线程安全尽量使用atomic系列
 * */
void one() {
    for (int i = 0; i < 10000; i++) {
        x++;
    }
}

void two() {
    for (int i = 0; i < 10000; i++) {
        xx++;
    }
}

void three() {
    for (int i = 0; i < 10000; i++) {
        xxx++;
    }
}

int main() {
    thread o(one);
    thread t(one);
    o.join();
    t.join();
    cout << "use volatile" << endl;
    cout << x << endl;
    thread A(two);
    thread B(two);
    A.join();
    B.join();
    cout << "use int" << endl;
    cout << xx << endl;
    thread C(three);
    thread D(three);
    C.join();
    D.join();
    cout << "use atomic" << endl;
    cout << xxx << endl;
    return 0;
}