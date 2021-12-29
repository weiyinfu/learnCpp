#include <boost/filesystem.hpp>
#include <iostream>
#include<stdlib.h>
using namespace std;
using namespace boost::filesystem;

void listdir(const char *dirname) {
    if (!exists(dirname)) {
        cout << dirname << " not exists" << endl;
        return;
    }
    if (is_regular_file(dirname)) {
        cout << dirname << " is regular file" << endl;
    }
    for (directory_entry &x: directory_iterator(dirname)) {
        cout << x.path() << endl;
    }
}

int main() {
    const char *home=getenv("HOME");
    listdir(home);
    return 0;
}
