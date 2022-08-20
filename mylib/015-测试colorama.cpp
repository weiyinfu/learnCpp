#include <clusterkit.hpp>
#include <iostream>
using namespace std;
using namespace clusterkit;
int main() {
  cout << colorama::FORE.RED << "hello" << colorama::FORE.BLUE << "world"
       << colorama::FORE.RESET << "over" << endl;
  return 0;
}