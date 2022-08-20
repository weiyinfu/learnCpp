#include <boost/assert.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>
using namespace std;
/**
 * C语言的assert无路如何也不能输出当前变量的一些信息
 */
int main() {
  int x = 3;
  string badInfo =
      "x should bigger than 4,but now is " + boost::lexical_cast<string>(x);
  BOOST_ASSERT_MSG(x > 4, badInfo.c_str());
  return 0;
}