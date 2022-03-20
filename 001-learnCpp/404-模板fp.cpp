#include<iostream>

using namespace std;

class Add {
public:
    int operator()(int x, int y) {
        return x + y;
    }
};

int sub(int x, int y) {
    return x - y;
}

template<class Fp>
int apply(int x, int y, Fp handler) {
    return handler(x, y);
}

int main() {
    Add a;
    cout << apply(1, 2, a) << endl;
    cout << apply(1, 2, sub) << endl;
    return 0;
}