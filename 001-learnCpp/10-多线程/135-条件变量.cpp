#include<thread>
#include<iostream>
#include<mutex>

using namespace std;
mutex m;
condition_variable v;

/**
 * condition_variable的原理：首先它需要传入一个已经获取了的锁，它会再次调用它的lock方法，因为是第二次lock，所以会阻塞。
 * 调用condition_variable.notify的时候，就会触发锁的释放。
 * */
void demo1() {
    unique_lock<mutex> l(m);
    cout << l.owns_lock() << endl;
//    l.lock();//再次申请锁就会死锁
    l.unlock();
    cout << "unlock" << endl;
}

int main() {
    //lock的加锁和解锁
    unique_lock<mutex> l(m);
    thread releaseLock([]() {
        this_thread::sleep_for(chrono::seconds(3));
        v.notify_all();
        cout << "over";
    });
    releaseLock.detach();
    v.wait(l);
    //wait的四种写法
    //v.wait_for(l, chrono::seconds(3));
    //v.wait_until
    v.wait(l, []() { return true; });//一直等待到特定条件达成
    cout << "good" << endl;
    return 0;
}