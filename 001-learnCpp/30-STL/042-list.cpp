#include <list>
#include <time.h>
#include <iostream>

using namespace std;

int main() {
    list<int> a;
    for (auto i = 0; i < 1000000; i++) {
        a.push_back(i);
    }
    auto beginTime = time(nullptr);
    int s = 0;
    int loopCount = int(1e6);
    cout << a.size() << endl;
    for (auto i = 0; i < loopCount; i++) {
        a.size();
        s += i;
    }
    auto endTime = time(nullptr);
    cout << "time1 " << endTime - beginTime << endl;
    beginTime = time(nullptr);
    s = 0;
    for (auto i = 0; i < loopCount; i++) {
        for (auto j = 0; j < a.size(); j++) {
            s += i * j;
        }
    }
    endTime = time(nullptr);
    cout << "time2 " << endTime - beginTime << endl;
    return 0;
}