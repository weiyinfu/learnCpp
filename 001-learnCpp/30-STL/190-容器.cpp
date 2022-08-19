#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

template<typename T>
string showVector(vector<T> a) {
    stringstream o;
    for (int i = 0; i < a.size(); i++) {
        o << a[i] << ",";
    }
    return o.str();
}

int main() {
    vector<int> v;
    cout << "v.size() == " << v.size() << " v.capacity() = " << v.capacity() << endl;
    v.reserve(10);
    cout << "v.size() == " << v.size() << " v.capacity() = " << v.capacity() << endl;
    v.resize(10);
    v.push_back(0);
    cout << "v.size() == " << v.size() << " v.capacity() = " << v.capacity() << endl;
    int a[4] = {1, 2, 3, 4};
    v.assign(a, a + 4);
    cout << showVector(v) << endl;
    cout << "size=" << v.size() << ",capacity" << v.capacity() << endl;
    return 0;
}