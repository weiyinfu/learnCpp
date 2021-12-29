#include <boost/filesystem.hpp>
#include <iostream>

using namespace std;
using namespace boost::filesystem;

int main() {
    path p(__FILE__);
    cout << "filename" << p.filename() << endl;
    cout << "root_directory" << p.root_directory() << endl;
    cout << "root_name" << p.root_name() << endl;
    cout << "root_path" << p.root_path() << endl;
    cout << "parent_path" << p.parent_path() << endl;
    cout << "extension:" << p.extension() << endl;
    cout << "is_absolute" << p.is_absolute() << endl;
    cout << p.size() << endl;
    return 0;
}