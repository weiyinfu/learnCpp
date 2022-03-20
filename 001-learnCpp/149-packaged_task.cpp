#include <iostream>
#include <type_traits>
#include <future>
#include <thread>

using namespace std;
/**
 * std::packaged_task<>将一个可调用对象（即需要执行的任务）或函数和一个future封装在一起的可调用对象。当构造一个 std::packaged_task<> 实例时,必须传入一个函数或可调用对象,这个函数或可调用的对象需要能接收指定的参数和返回可转换为指定返回类型的值。类型可以不完全匹配;比如使用float f(int )函数,来构建 std::packaged_task<double(double)> 的实例,因为在这里,类型可以隐式转换。使用std::packaged_task关联的std::future对象保存的数据类型是可调对象的返回结果类型，如示例函数的返回结果类型是int，那么声明为std::future<int>，而不是std::future<int(int)
 * */
int main() {
    std::packaged_task<int()> task([]() {
        std::this_thread::sleep_for(std::chrono::seconds(5));// 线程睡眠5s
        return 4;
    });
    std::thread t1(std::ref(task));
    std::future<int> f1 = task.get_future();

    auto r = f1.get();// 线程外阻塞等待
    std::cout << r << std::endl;
    t1.join();
    return 0;
}