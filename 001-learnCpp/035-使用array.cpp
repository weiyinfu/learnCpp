#include <algorithm>
#include <array>
#include <iostream>
using namespace std;
void show(array<int, 10> a) {
  for_each(a.begin(), a.end(), [](auto x) { cout << x << ","; });
  cout << endl;
}
int main() {
  array<int, 10> a = {1, 2, 3, 4};
  a[9] = 1223;
  cout << a.size() << endl;
  show(a);
  int *x = a.data();
  x[3] = 432;
  show(a);
  show(a);
}