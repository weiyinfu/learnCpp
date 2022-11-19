#include <thread>
#include <vector>
#include <iostream>
#include <atomic>

std::atomic_flag lock = ATOMIC_FLAG_INIT;
/*
 * 成员函数
	(构造函数)	构造 atomic_flag(公开成员函数)
	operator=	赋值运算符(公开成员函数)
	clear	原子地设置标志为 false(公开成员函数)
	test_and_set	原子地设置标志为 true 并获得其先前值(公开成员函数)
	test(C++20)	原子地返回标志的值(公开成员函数)
	wait(C++20)	阻塞线程直至被提醒且原子值更改(公开成员函数)
	notify_one(C++20)	提醒至少一个在原子对象上的等待中阻塞的线程(公开成员函数)
	notify_all (C++20)	提醒所有在原子对象上的等待中阻塞的线程
 * */
void f(int n) {
    for (int cnt = 0; cnt < 100; ++cnt) {
        while (lock.test_and_set(std::memory_order_acquire))  // 获得锁
            ; // 自旋
        std::cout << "Output from thread " << n << '\n';
        lock.clear(std::memory_order_release);               // 释放锁
    }
}

int main() {
    std::vector<std::thread> v;
    for (int n = 0; n < 10; ++n) {
        v.emplace_back(f, n);
    }
    for (auto &t: v) {
        t.join();
    }
}