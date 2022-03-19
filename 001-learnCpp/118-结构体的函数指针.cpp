#include<iostream>
#include <string>

using namespace std;

struct Haha {
    int x;

    Haha(int x) {
        this->x = x;
    }

    int add(int x, int y);

    static int add2(int x, int y);
};

int Haha::add(int x, int y) {
    return this->x + x + y;
}

int Haha::add2(int x, int y) {
    return x + y;
}

typedef int (*Fun)(int, int);

int handle(int x, int y, Fun f) {
    return f(x, y);
}

int main() {
    Haha m(1);
    Haha n(2);
    //报错：reference to non-static function must be called
    //cout << handle(1, 2, m.add);
    cout << handle(1, 2, Haha::add2) << endl;
    //使用lambda表达式的时候，不能使用捕获
    cout << handle(1, 2, [](int x, int y) -> int {
        return x * y;
    }) << endl;
    return 0;
}