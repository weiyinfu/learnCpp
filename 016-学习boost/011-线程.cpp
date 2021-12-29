#include <boost/thread.hpp>
#include <iostream>

void hello() { std::cout << "Hello world, I'm a thread!" << std::endl; }

//编译时，需要libboost_thread/libpthread
int main(int argc, char *argv[]) {
    boost::thread thrd(&hello);
    thrd.join();
    return 0;
}