#include <iostream>

using namespace std;

class Fraction {
    //定义一个分数类
public:
    double up, down;

    Fraction(double up, double down) {
        this->up = up;
        this->down = down;
    }

    Fraction operator+(Fraction x) {
        double d = down * x.down;
        double u = down * x.up + up * x.down;
        return Fraction(u, d);
    }

    Fraction operator-(Fraction x) {
        auto y = x;
        y.up *= -1;
        return *this + y;
    }

//
//    ostream &operator<<(ostream &o) const {
//        o << up << '/' << down;
//        return o;
//    }
    friend ostream &operator<<(ostream &o, Fraction f) {
        o << f.up << "/" << f.down;
        return o;
    }

    friend Fraction operator*(Fraction x, Fraction y) {
        //使用括号要比直接返回构造函数效率高
        //return Fraction(x.up*y.up,x.down*y.down);
        return {x.up * y.up, x.down * y.down};
    }
};

//使用友元函数实现乘法和触发
int main() {
    Fraction a(3, 4);
    Fraction b(1, 2);
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a + b * b << endl;
    return 0;
}