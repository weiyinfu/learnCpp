#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;
using namespace std;

void print_files(const path &full_path) {
  if (exists(full_path)) {
    directory_iterator item_begin(full_path);
    directory_iterator item_end;

    for (; item_begin != item_end; ++item_begin) {
      if (is_directory(*item_begin)) {
        cout << item_begin->path().native() << "\t[dir]" << endl;
        print_files(item_begin->path()); //此处递归调用打印树形结构
      } else {
        cout << item_begin->path().native() << endl;
      }
    }
  } else {
    throw "folder not exits";
  }
}

int main(int argc, const char **argv) {
  path full_path(".");
  print_files(full_path);
}