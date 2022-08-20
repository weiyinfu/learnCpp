#include <NumCpp.hpp>
#include <array>
#include <iostream>
using namespace std;
int main() {
  nc::NdArray<int> a = {{1, 2}, {3, 4}, {5, 6}};
  cout << a << endl;
  return 0;
}
