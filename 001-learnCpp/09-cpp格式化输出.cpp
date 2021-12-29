#include <iomanip> //不要忘记包含此头文件
#include <iostream>

using namespace std;

int main() {
    int a = 32;
    cout << "dec:" << dec << a << endl;        //以十进制形式输出整数
    cout << "hex:" << hex << a << endl;        //以十六进制形式输出整数a
    cout << "oct:" << setbase(8) << a << endl; //以八进制形式输出整数a
    char *pt = "China";                        // pt指向字符串"China"
    cout << setw(10) << pt << endl;            //指定域宽为,输出字符串
    cout << setfill('*') << setw(10) << pt
         << endl;           //指定域宽,输出字符串,空白处以'*'填充
    double pi = 22.0 / 7.0; //计算pi值
    //按指数形式输出,8位小数
    cout << setiosflags(ios::scientific) << setprecision(8);
    cout << "pi=" << pi << endl;                            //输出pi值
    cout << "pi=" << setprecision(4) << pi << endl;         //改为位小数
    cout << "pi=" << setiosflags(ios::fixed) << pi << endl; //改为小数形式输出
    return 0;
}