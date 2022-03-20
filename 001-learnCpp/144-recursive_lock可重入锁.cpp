#include<iostream>
#include<mutex>
#include<thread>

using namespace std;
mutex m;
recursive_mutex mm;

void one() {
    //lock_guard比较简陋，一个函数都没有，在析构的时候释放
    lock_guard<mutex> l(m);
    lock_guard<mutex> ll(m);//执行两次加锁会报错
}

void two() {
    //unique_lock可以看做是lock_guard的进阶版，提供了一些lock、unlock函数
    unique_lock<mutex> l(m);
    l.lock();//执行第二次锁定会报错
}

void three() {
    //使用可重入锁
    lock_guard<recursive_mutex> l(mm);
    lock_guard<recursive_mutex> ll(mm);
}

int main() {
    three();
    return 0;
}