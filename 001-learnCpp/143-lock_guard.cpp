#include <list>
#include <mutex>
#include <algorithm>
#include <iostream>
using namespace std;
std::list<int> some_list;
std::mutex some_mutex;
/*
 * lock_guard是一个类，在它执行析构的时候就会自动释放锁。
 * lock_guard是最简单的锁
 * */
void add_to_list(int new_value) {
    std::lock_guard<std::mutex> guard(some_mutex);
    some_list.push_back(new_value);
}

bool list_contains(int value_to_find) {
    std::lock_guard<std::mutex> guard(some_mutex);
    return std::find(some_list.begin(), some_list.end(), value_to_find)
           != some_list.end();
}

int main() {
    add_to_list(42);
    std::cout << "contains(1)=" << list_contains(1) << ", contains(42)=" << list_contains(42) << std::endl;
}