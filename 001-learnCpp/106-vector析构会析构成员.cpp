#include<vector>
#include <iostream>

using namespace std;

struct User {
    ~User() {
        cout << "delete user" << endl;
    }
};

int main() {
    auto a = new vector<User *>;
    for (auto i = 0; i < 10; i++) {
        a->push_back(new User);
        cout << "pushback" << endl;
    }
    delete a;
    cout << "game over";
    while (true);
}