#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;
using namespace std;
#define LOG(x)                                                                 \
  cout << __FILE__ << ':' << __LINE__ << ' ' << (__FUNCTION__) \
                       << ' '<<x<<endl;

int main(int argc, char *argv[]) {
    //C++像python一样，也能够获取当前文件的名称、当前文件的地址。
    cout << __FUNCTION__ << ":" << __func__ << endl;
    cout << "FILENAME:" << __FILE_NAME__ << endl;
    cout << "FILE:" << __FILE__ << endl;
    uintmax_t sz = file_size(__FILE__);
    std::cout << file_size(__FILE__) << '\n';
    std::cout << sz << std::endl;
    cout << "文件是否存在：" << exists(__FILE__) << endl;
    cout << "文件是否为regular_file：" << is_regular_file(__FILE__) << endl;
    cout << "文件是否为目录：" << is_directory(__FILE__) << endl;

    LOG("这是一行日志");
    return 0;
}