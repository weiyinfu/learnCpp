#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/process.hpp>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
using namespace std;
string callSystemCommand(string cmd) {
  boost::process::pstream pio;
  boost::process::system(cmd, boost::process::std_out > pio);
  std::ostringstream o;
  o << pio.rdbuf();
  return o.str();
}
int main() {
  auto content = callSystemCommand("/usr/bin/lscpu");
  smatch m;
  regex e("CPU\\(s\\):\\s+(\\d+)\n");
  regex_search(content, m, e);
  cout << m[1].str() << endl;
  // std::cout << content << std::endl;
  boost::trim(content);
  return 0;
}
