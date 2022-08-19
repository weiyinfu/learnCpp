#include <iostream>

using namespace std;
/*
 * 对于函数名add，add、*add、&add三者等价，都指向函数首地址；
 * 对于函数指针f，f 和 *f 等价，同样是指向函数首地址；
 * 而&f 为函数指针的地址，因为函数指针 f 的值可变，可指向不同的函数。
 * */
int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

typedef int (*op)(int, int);

int run(op o, int x, int y) {
    return o(x, y);
}

int main() {
    cout << run(add, 1, 2) << endl;
    cout << run(sub, 1, 2) << endl;
    cout << run(&sub, 1, 2) << endl;
    cout << run(&add, 1, 2) << endl;
    cout << (op) (add) << endl;
    cout << (op) (&add) << endl;
    cout << (op) (sub) << endl;
    cout << (op) (&sub) << endl;
    return 0;
}
