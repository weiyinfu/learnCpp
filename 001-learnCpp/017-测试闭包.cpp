#include <assert.h>
#include <iostream>
using namespace std;
int main() {
  int y = 3;
  int x = [&]() { return y + 1; }();
  cout << x << endl;
  assert(x < 5 || [&]() {
    cout << "found error" << endl;
    exit(-1);
    return false;
  }());
  return 0;
}