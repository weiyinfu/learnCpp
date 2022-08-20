#include "clusterkit/data/store.hpp"
#include <iostream>
using namespace std;
int main() {
  cout << clusterkit::s3::pathJoin({"one/", "two", "three/"}) << endl;
  return 0;
}