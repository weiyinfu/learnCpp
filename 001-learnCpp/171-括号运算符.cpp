#include<iostream>

using namespace std;

class MyOperator {
public:
    int base;

    MyOperator(int base) {
        this->base = base;
    }

    int operator()(int a, int b, int c) {
        return a * (b + c) + base;
    }
};

int main() {
    auto x = MyOperator(5)(1, 2, 3);
    cout << x << endl;
    cout << 1 * (2 + 3) + 5 << endl;
    return 0;
}