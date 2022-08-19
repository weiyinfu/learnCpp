#include <mutex>

class some_big_object {
};

void swap(some_big_object &lhs, some_big_object &rhs) {}

class X {
private:
    some_big_object some_detail;
    mutable std::mutex m;
public:
    X(some_big_object const &sd) : some_detail(sd) {}

    friend void swap(X &lhs, X &rhs) {
        if (&lhs == &rhs)
            return;
        std::lock(lhs.m, rhs.m);
        //提供 std::adopt_lock 参数除了表示 std::lock_guard 的对象已经上锁外,还表示应使用互斥量现成的锁,而非尝试创建新的互斥锁。
        std::lock_guard<std::mutex> lock_a(lhs.m, std::adopt_lock);
        std::lock_guard<std::mutex> lock_b(rhs.m, std::adopt_lock);
        swap(lhs.some_detail, rhs.some_detail);
    }
};

int main() {}