#include <boost/thread.hpp>
#include <iostream>

boost::mutex io_mutex;

struct count {
    //构造函数
    count(int id) : id(id) {}

    //实现括号运算符
    void operator()() {
        for (int i = 0; i < 10; ++i) {
            //此处尝试获取lock，在它的析构函数中会释放锁
            boost::mutex::scoped_lock lock(io_mutex);
            std::cout << id << ": " << i << std::endl;
        }
    }

    int id;
};

int main(int argc, char *argv[]) {
    boost::thread thrd1(count(1));
    boost::thread thrd2(count(2));
    thrd1.join();
    thrd2.join();
    return 0;
}