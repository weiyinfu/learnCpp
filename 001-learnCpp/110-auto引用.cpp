#include<iostream>

using namespace std;

/**
 * auto x=...;默认情况下x一定不是引用。
 * */
struct User {
    int age;
};
User *uu = nullptr;

User &GetUser() {
    if (uu != nullptr) {
        return *uu;
    }
    cout << "creating user" << endl;
    auto u = new User;
    u->age = 10;
    uu = u;
    return *u;
}

int main() {
    auto u = GetUser();//此处u不是引用，而是拷贝了一份数据。改它的数据不会影响全局
    u.age = 100;
    auto uu = GetUser();
    cout << uu.age << endl;
    //使用auto&，获取引用，修改会影响全局
    auto &uuu = GetUser();
    uuu.age = 100;
    auto uuuu = GetUser();
    cout << uuuu.age << endl;
    return 0;
}