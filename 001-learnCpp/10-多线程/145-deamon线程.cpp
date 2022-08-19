#include<thread>
#include<iostream>
#include<chrono>

using namespace std;

/**
 * 线程分为两种：后台线程和前台线程。对于后台线程，当主线程结束，后台线程随之结束；对于前台线程，当主线程结束，后台线程会报错。
 * 在创建线程的时候，线程默认是deamon=False，也就是前台线程，表示线程不是后台线程。
 * 使用detach方法可以把线程变成一个后台线程。
 * */
void go() {
    this_thread::sleep_for(chrono::seconds(3));
}

int main() {
    thread haha(go);
    haha.detach();//如果没有这句话，程序运行会报错
//    this_thread::sleep_for(chrono::seconds(5));
    return 0;
}