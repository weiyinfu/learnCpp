#include <iostream>
#include <json.hpp>
using namespace std;
using json = nlohmann::json;
int main() {
  json a = {{"one", 1}, {"two", 2}};
  cout << a << endl;
  return 0;
}