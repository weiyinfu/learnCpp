#include<iostream>
#include<atomic>

using namespace std;

atomic_int64_t x(0);

void one() {
    cout << x.load() << endl;
    x = 234;
    cout << x << endl;
    cout << x.load() << endl;
}

int main() {
    atomic<time_t> x = {3};
    cout << x << endl;
    cout << x.load() << endl;
    x = time(nullptr);
    cout << x << endl;
    cout << x.load() << endl;
    return 0;
}