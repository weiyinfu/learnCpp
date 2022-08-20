#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
int main() {
  using namespace std;
  puts("haha");
  cout << "haha";
  cout << "\rbaga";
  puts("haha");
  puts("\rbaga");
  stringstream baga("1 2  3");
  int v;
  while (baga >> v) {
    cout << v << endl;
  }
  return 0;
}