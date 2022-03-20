#include <iostream>
#include <thread>
#include <future>

std::string taskFunc1() {
    std::string str = "This is task1";
    return str;
}

std::string taskFunc2() {
    std::string str = " and task2";
    return str;
}

//基于任务的编程
int main() {
    auto fut1 = std::async(taskFunc1);
    auto fut2 = std::async(taskFunc2);

    std::cout << fut1.get() + fut2.get() << std::endl << "This is main program" << std::endl;

    return 0;
}