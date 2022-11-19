#include<iostream>
#include <sstream>

using namespace std;

int main() {
    size_t x = 1;
    size_t y = 2;
    stringstream o;
    o << x << "," << y << endl;
    cout << o.str() << endl;
    return 0;
}