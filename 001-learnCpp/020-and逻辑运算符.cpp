#include <iostream>
#include <string>
using namespace std;
bool one(string info) {
  cout << info << endl;
  return true;
}
int main() {
  auto x = one("one") && one("two");

  return 0;
}