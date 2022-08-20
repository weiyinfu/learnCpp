#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>

#include <streambuf>
using namespace std;
/*
读取流的全部内容的若干种方法
*/
stringstream get() {
  stringstream x;
  x << "one " << 3 << " two " << 4;
  return x;
}
void test0() {
  auto in = get();
  std::string some_str;
  in >> some_str; //这种方式有风险，因为它只读了第一个字符串
  cout << some_str << endl;
}
void test2() {
  auto in = get();
  std::istreambuf_iterator<char> begin(in);
  std::istreambuf_iterator<char> end;
  std::string some_str(begin, end);
  cout << some_str << endl;
}
void test3() {
  auto in = get();
  std::ostringstream tmp;
  tmp << in.rdbuf();
  std::string str = tmp.str();
  cout << str << endl;
}
void test4() {
  std::ifstream t;
  int length;
  t.open("file.txt");        // open input file
  t.seekg(0, std::ios::end); // go to the end
  length = t.tellg();        // report location (this is the length)
  t.seekg(0, std::ios::beg); // go back to the beginning
  auto buffer =
      new char[length]; // allocate memory for a buffer of appropriate dimension
  t.read(buffer, length); // read the whole file into the buffer
  t.close();              // close file handle

  // ... do stuff with buffer here ...
}
int main() { test3(); }