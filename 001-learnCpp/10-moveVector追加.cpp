#include <iterator>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
//通过std::move实现把一个对象的内容复制到另一个对象。
void MoveAppend(vector<int> &src, vector<int> &dst) {
    if (dst.empty()) {
        dst = move(src);
    } else {
        dst.reserve(dst.size() + src.size());
        move(begin(src), end(src), back_inserter(dst));
        src.clear();
    }
}

int main() {
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {5, 6, 7, 8};
    MoveAppend(a, b);
    cout << a.size() << endl;
    cout << b.size() << endl;
    return 0;
}