#include <thread>
#include <iostream>
#include<atomic>
#include<random>
#include<thread>
#include<vector>

using namespace std;
thread_local vector<long> a;

/*
 * 在Java中，thread_local只是一个数据结构，在Cpp中thread_local是一个类型修饰符
 * */
void haha() {
    auto x = random();
    a.push_back(x);
    cout << a.size() << endl;
}

int main() {
    thread A(haha);
    thread B(haha);
    A.join();
    B.join();
    cout << "main thread" << a.size() << endl;
    return 0;
}