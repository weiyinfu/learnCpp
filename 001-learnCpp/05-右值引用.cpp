#include <iostream>
#include <vector>

using namespace std;

class A {
};

vector<int> getVector() {
    vector<int> a;
    cout << &a << endl;
    return a;
}

A getA() {
    A a;
    cout << &a << endl;
    return a;
}

void testVector() {
    vector<int> a = getVector();
    cout << "a  " << &a << endl;
    vector<int> b = a;
    cout << "b  " << &b << endl;
}

void testA() {
    A a = getA();
    cout << &a << endl;
}

int main() {
    testA();
    testVector();
    return 0;
}