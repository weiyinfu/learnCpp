#include <iostream>
#include<string>

using namespace std;

class UserManager {
public:
    static UserManager manager;

    static UserManager *getInstance() {
        static UserManager manager;
        return &manager;
    }

    string name;
};

int main() {
    auto manager = UserManager::getInstance();
    manager->name = "one";
    cout << manager->name << endl;
    auto m = UserManager::getInstance();
    cout << (m == manager) << endl;
    cout << m->name << endl;
}