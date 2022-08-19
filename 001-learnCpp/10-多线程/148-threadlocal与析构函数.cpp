#include <thread>
#include <iostream>

using namespace std;

class Haha {
public:
    Haha() {
        cout << "haha is created" << endl;
    }

    ~Haha() {
        cout << "haha is deleted" << endl;
    }
};


thread_local Haha ha;

void go(int x) {
    cout << &ha << endl;//如果这里没有用到ha，则ha不会被创建。
    cout << "go" << x << endl;
}

void run() {
    thread one(go, 1);
    thread two(go, 2);
    one.join();
    two.join();
}

int main() {
    run();
    return 0;
}