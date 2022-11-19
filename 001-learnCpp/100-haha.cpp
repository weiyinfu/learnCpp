#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>

using namespace std;

typedef struct haha *hahaHandle;
class haha{
    int x=3;
};
int main() {
    cout << "hello world" << endl;
    vector<int> *vec = new vector<int>();
    unique_ptr<vector<int>> x(vec);
    cout << sizeof(size_t) << endl;
    haha h;

    unsigned  long long x=-1;
    printf("%llu",x);
    return 0;
}