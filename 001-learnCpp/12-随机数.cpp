#include<random>
#include<iostream>

using namespace std;

int main() {
    //stdlib中的随机数，不建议使用
    cout << rand() << endl;
    //random包中的随机数，现在鼓励使用random()而不鼓励使用rand()，因为C++的random包具备更好的随机性
    cout << random() << endl;
    return 0;
}