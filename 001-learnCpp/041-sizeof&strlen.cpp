#include<iostream>

using namespace std;

int main() {
//32bit
    const char *p = "hello\n\\";
    char m[8] = {'1', '2', '0', '4', '0', '6'};

    int a = sizeof(p);        //输出4，或者8；因为p是一个指针，在32位机器上输出为4；在64位机器上输出为8
    int b = sizeof(*p);        //输出1,相当于sizeof(char),一个char占1个字节
    int c = strlen(p);        //输出7，真实的字符串长度，不包括最后的0
    int d = sizeof(m);        //输出8，m数组对应的指针中元素的个数
    int e = strlen(m);        //输出6//真实的字符串长度，不包括最后的0
    cout << a << b << c << d << e << endl;
    return 0;
}