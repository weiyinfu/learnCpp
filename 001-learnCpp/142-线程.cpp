#include <thread>
#include <iostream>
#include <atomic>

using namespace std;
volatile int x = 0;
int xx = 0;
atomic_int xxx(0);

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
    cout << xx << endl;
    thread C(three);
    thread D(three);
    C.join();
    D.join();
    cout << xxx << endl;
    return 0;
}