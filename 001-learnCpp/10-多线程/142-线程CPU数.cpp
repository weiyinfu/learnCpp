#include <thread>
#include <iostream>
#include <atomic>

using namespace std;

int main() {
    cout << thread::hardware_concurrency() << endl;
    cout << this_thread::get_id() << endl;
    return 0;
}