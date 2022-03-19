#include <iostream>

using std::cout;
using std::endl;
/**
 * https://blog.csdn.net/e21105834/article/details/119203737
 * */
void xprintf() {
    cout << endl;
}

template<typename T, typename... Targs>
void xprintf(T value, Targs... Fargs) {
    cout << value << ' ';
    if ((sizeof ...(Fargs)) > 0) {
        //这里调用的时候没有显式指定模板，是因为函数模板可以根据函数参数自动推导
        xprintf(Fargs...);
    } else {
        xprintf();
    }
}

int main() {
    xprintf("小明个人信息:", "小明", "男", 35, "程序员", 169.5);
    return 0;
}