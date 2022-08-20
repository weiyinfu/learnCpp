#include <boost/log/trivial.hpp>
#include <clusterkit/util/log.hpp>
#include <iostream>
using namespace std;
int main() {
  LOG(trace) << "one";
  LOG(info) << "two";
}