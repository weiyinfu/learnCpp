#include <iostream>
#include <locale.h>
#include <locale>
#include <stdio.h>
#include <wchar.h>

using namespace std;
void test2() {
  // 注意，此文档最好采用utf-8编码

  //此语句重要，在win7 + vs2012和 ubuntu 12.04测试结果一致
  //只要打印wchar_t字符，均加此语句，至少不会出错，此语句最好在程序初始化处
  setlocale(LC_ALL, "");

  // wprintf和printf最好不能同时使用.
  // 如下使用printf同时打印了char字符串和wchar_t字符串
  // 因此只采用printf是比较好的方法
  wchar_t ws[] = L"国家";
  printf("printf content start: %ls\n", ws);
  printf("content end\n");
}
void test1() {
  // wcout.imbue(std::locale("chs"));
  std::locale loc("");
  std::wcout.imbue(loc);
  std::locale::global(std::locale(""));
  // wchar_t x = L'█';
  string x = "█";
  wchar_t sss[100] = L"我是中国人";
  wcout << sss << endl;
  cout << printf("%s", x.c_str())
       << "printf return value"; // printf的返回值就是它写成功的字符个数
  cout << sizeof(x.c_str()) << endl;
  for (int i = 0; i < 10; i++)
    cout << x;
  cout << '$' << endl;
  for (int i = 0; i < 10; i++) {
    cout << ' ';
  }
  cout << '$' << endl;
}
int main() {
  test1();
  return 0;
}