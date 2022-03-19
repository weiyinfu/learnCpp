#include<iostream>

using namespace std;

class Inner {
public:
    void haha() {
        cout << "haha" << endl;
    }
};

class Outter {
public:
    Inner i;

    void out_haha() {
        cout << "out haha" << endl;
    }

    Inner *operator->() {
        return &i;
    }
};

int main() {
    Outter o;
    o->haha();
    o.out_haha();//既可以当做指针，又可以当做对象
    return 0;
}