#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>
using namespace std;
int main()
{
  cout << "hello world" << endl;
  vector<int> *vec = new vector<int>();
  unique_ptr<vector<int>> x(vec);
  return 0;
}