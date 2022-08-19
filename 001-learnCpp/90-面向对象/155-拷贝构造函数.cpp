#include<iostream>

using namespace std;

class One {
public:
    One() {
        cout << "构造函数" << endl;
    }

    One(const One &o) {
        cout << "复制构造函数" << endl;
    }
};

int main() {
    One o;//执行构造函数
    One oo = o;//执行复制构造函数
    One ooo = One();//先执行构造函数，在执行复制构造函数
    return 0;
}