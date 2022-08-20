#include <iostream>
using namespace std;
int main() {
  string s("haha");
  const char *data = s.data();
  char *a = const_cast<char *>(data);
  a[0] = 'H';
  cout << s << endl;
  return 0;
}