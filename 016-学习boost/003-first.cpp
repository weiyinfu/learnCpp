#include <algorithm>
#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>

/**
 * 输入一个数字，打印它的三倍。使用boost中的lambda
 * */
int main() {
  using namespace boost::lambda;
  typedef std::istream_iterator<int> in;

  std::for_each(in(std::cin), in(), std::cout << (_1 * 3) << " ");
}