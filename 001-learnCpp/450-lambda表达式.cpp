#include<iostream>

using namespace std;
/**
捕获形式：
 []	不捕获任何外部变量
[变量名, …]	默认以值得形式捕获指定的多个外部变量（用逗号分隔），如果引用捕获，需要显示声明（使用&说明符）
[this]	以值的形式捕获this指针
[=]	以值的形式捕获所有外部变量
[&]	以引用形式捕获所有外部变量
[=, &x]	变量x以引用形式捕获，其余变量以传值形式捕获
[&, x]	变量x以值的形式捕获，其余变量以引用形式捕获
 * */
int main() {
    int x = 3;
    int y = 6;
    auto f = [&x, &y]() {
        x = -3;
        y = -6;
    };
    f();
    cout << x << endl;
    cout << y << endl;

    int a = 123;
    auto ff = [a] { cout << a << endl; };   // 值捕获外部本地变量a
    ff(); // 输出：123

    //或通过“函数体”后面的‘()’传入参数
    auto xx = [](int a){cout << a << endl; return 0; }(123);  // 显示传入外部变量值（值传递）给lambda表达式，输出123


    auto refFunction = [&a] { cout << a << endl; };  // 通过lambda表达式定义函数，引用捕获外部变量
    a = 321;
    refFunction(); //调用lambda函数，输出：321


    auto fvalue = [=] { cout << a << endl; };    // 隐式值捕获外部所有变量
    fvalue(); // 输出：321

    auto fref = [&] { cout << a << endl; };    // 隐式引用捕获外部所有变量
    a = 321;
    fref(); // 输出：321
}