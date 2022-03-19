#include<iostream>
#include<map>
#include<list>

using namespace std;

int main() {
    map<string, int> a = {
            {"one", 1},
            {"two", 2},
            {"one", 3}
    };
    list<pair<string, int>> b(a.begin(), a.end());
    for (const auto &i: b) {
        cout << i.first << "=>" << i.second << endl;
    }
    for (const auto &i: a) {
        cout << i.first << "=>" << i.second << endl;
    }
    multimap<string, int> ma = {
            {"one", 1},
            {"one", 2},
    };
    for (auto i = ma.begin(); i != ma.end(); i++) {
        cout << i->first << "=>" << i->second << endl;
    }
    return 0;
}