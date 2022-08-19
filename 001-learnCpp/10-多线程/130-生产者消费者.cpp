#include <iostream>
#include <thread>
#include <atomic>
#include <condition_variable>
#include <mutex>

std::mutex _mutex;                 /*线程锁*/
std::condition_variable cv;           /*条件变量*/
std::atomic_int productCnt(0);   /*公共变量，产品库存数量*/
std::atomic_bool isReady(false);  /*公共变量，防止假性唤醒线程*/
/*生产产品*/
void producer() {
    while (true) {
        std::unique_lock<std::mutex> lock(_mutex);
        std::cout << "+++生产了产品, 库存剩余:" << ++productCnt << std::endl;
        isReady = true;   /*产品生产好了*/
        cv.notify_all();  /*唤醒线程，通知Fun2()产品可以卖了*/
        cv.wait(lock);      /*睡眠线程，Fun1()在等待Fun2()把产品卖出去再生产*/
    }
}

/*销售产品*/
void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(_mutex);
        /*Fun1()产品还没生产好，Fun2()在这睡大觉*/
        if (!isReady) {
            cv.wait(lock);
        }
        std::cout << "---卖出了产品, 库存剩余:" << --productCnt << std::endl;
        isReady = false;/*Fun2()把产品买出去啦*/
        cv.notify_all();/*Fun2()告诉Fun1()产品已经卖了，可以继续生产了*/
    }
}

/*主函数*/
int main(int argc, char **argv) {
    std::thread t1(consumer);/*声明线程1*/
    std::thread t2(producer);/*声明线程2*/
    t1.join();/*开启线程1*/
    t2.join();/*开启线程2*/
    return 0;
}
