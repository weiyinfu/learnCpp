#include <iostream>

using namespace std;

#define MIN(a, b) (a<b ? a : b)
#define MKSTR(x) #x//表示把x当做一个字符串
#define concat(a, b) a ## b//表示字符串拼接

int main() {
    int i, j;
    i = 100;
    j = 30;
    cout << "较小的值为：" << MIN(i, j) << endl;
    cout << MKSTR(Hello world这种非常难以解析) << endl;
    int xy = 100;
    cout << concat(x, y) << endl;//把xy拼起来作为一个变量
    return 0;
}