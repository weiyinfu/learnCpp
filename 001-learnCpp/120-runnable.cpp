#include <iostream>
#include <string>
#include<vector>

using namespace std;

class Runnable {
public:
    void run() {

    }
};

class One : public Runnable {
private:
    int x;
public:
    One(int x) {
        this->x = x;
    }

    void run() const {
        cout << "One" << x << endl;
    }
};

class Two : public Runnable {
private :
    string x;
public:
    Two(string s) {
        x = s;
    }

    void run() const {
        cout << "Two" << x << endl;
    }
};

vector<Runnable> a;

int main() {
    auto one = One(1);
    a.push_back(one);
    auto two = Two("2");
    a.push_back(two);
    a.push_back(One(3));
    a.push_back(Two("4"));
    for (auto &i: a) {
        i.run();
    }
    return 0;
}