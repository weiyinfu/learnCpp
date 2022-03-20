#include<iostream>
#include<thread>

using namespace std;

int f() {
    return 3;
}

typedef void ff(int);

template<class Fp>
void asyncF(Fp fun) {
    thread x([fun]() {
        auto ans = f();
        fun(ans);
    });
    x.detach();
}
//
//class SyncF {

//public:
//    SyncF() {
//    }
//
//    void run(AsyncFun fun) {
//        unique_lock<mutex> l;
//        fun(this);
//        v.wait(l);
//    }
//
//    void operator()() {
//
//    }
//};

int syncF() {
    condition_variable v;
    mutex m;
    unique_lock<mutex> l(m);
    int real_ans;
    asyncF([&](int ans) {
        real_ans = ans;
        v.notify_all();
    });
    v.wait(l);
    return real_ans;
}

int main() {
    asyncF([](int ans) {
        cout << ans << endl;
    });
    cout << syncF() << endl;
    this_thread::sleep_for(chrono::seconds(3));
    return 0;
}