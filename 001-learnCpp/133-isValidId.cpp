#include<string>
#include<iostream>

using namespace std;

bool isValidId(std::string id) {
    //检查id是否合法
    if (id.empty()) {
        return false;
    }
    if (id.size() >= 128) {
        return false;
    }
    for (auto i = 0; i < id.size(); i++) {
        if (!(id[i] >= 'a' && id[i] <= 'z' || id[i] >= 'A' && id[i] <= 'Z' || id[i] >= '0' && id[i] <= '9' ||
              id[i] == '_' || id[i] == '-' || id[i] == '@')) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << isValidId("23423141") << endl;
    cout << isValidId("3asdfasdf-@asdf") << endl;
}