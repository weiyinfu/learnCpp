//class 子类: 继承方式 父类1，继承方式 父类2...
//多继承会引发，多父类中的成员名称冲突；需要加作用域；

class Base1 {
public:
    Base1() {
        a = 1;
    }

    int a;
};

class Base2 {
public:
    Base2() {
        a = 2;
    }

    int a;
};

class Son : public Base1, public Base2 {
public:
    int s;
};

//Son s;
//sizeof(s); 是12;
int main() {
    Son s;
//s.a;//报错，二义性，两个父类中都有a；需要加作用域区分
    s.Base1::a; //正确
    s.Base2::a; //正确
    return 0;
}