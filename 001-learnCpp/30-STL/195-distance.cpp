#include<set>
#include<iostream>
#include<vector>
#include<iterator>
#include<ctime>

using namespace std;

/**
 * C++中提供了distance函数，位于iterator头文件中。
 * 那么这个distance函数是如何实现的呢？
 * 如果是数组，则直接进行运算，效率很高；
 * 如果是multiset，虽然它是一个树状结构，但是它的distance实现是for循环遍历，性能比较低
 * */
void testVector() {
    vector<int> a;
    for (auto i = 0; i < 10000; i++) {
        a.push_back(i);
    }
    auto beg = time(0);
    for (auto i = 0; i < 10000; i++) {
        auto l = std::lower_bound(a.begin(), a.end(), 10);
        auto r = upper_bound(a.begin(), a.end(), 10000);
        auto ans = distance(l, r);
    }
    auto end = time(0);
    cout << end - beg << endl;
}

int main() {
    multiset<int> a;
    for (auto i = 0; i < 10000; i++) {
        a.insert(i);
    }
    {
        auto beg = time(0);
        for (auto i = 0; i < 10000; i++) {
            auto l = a.lower_bound(10);
            auto r = a.upper_bound(10000);
            auto ans = distance(l, r);
        }
        auto end = time(0);
        cout << end - beg << endl;
    }

    {
        auto beg = time(0);
        for (auto i = 0; i < 10000; i++) {
            auto l = a.lower_bound(10);
            auto r = a.upper_bound(10000);
            while (l != r)l++;
        }
        auto end = time(0);
        cout << "自己实现的distance：" << end - beg << endl;
    }

    testVector();
    return 0;
}