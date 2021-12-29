#include <boost/format.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    const char *COLOM_KEY = "Name";
    const char *tableName = "player";
    const char *key = "boost";
    boost::format fmt("select %1% from '%2%' where %1% = '%3%'");
    fmt % COLOM_KEY % tableName % key;

    std::string finalstr = fmt.str();
    const char *str = finalstr.c_str();

    cout << str << endl; //只是为了展示如何转换为char*

    boost::format fmt2("%s:%d + %d = %d\n");
    fmt2 % "sum" % 1 % 2 % (1 + 2);
    cout << fmt2.str();
    cout << boost::format("%s:%d + %d = %d\n") % "sum" % 1 % 2 % (1 + 2);

    boost::format fmt3("%05d\n%|-8.3f|\n%| 10s|\n%05X\n");
    cout << fmt3 % 62 % 2.236 % "123456" % 15;

    char a[100];
    cout << sprintf(a, "%d^2+%d^2=%d^2", 3, 4, 5) << endl;
    cout << a << endl;
    return 0;
}
