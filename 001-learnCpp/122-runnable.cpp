#include <iostream>
#include <string>
#include<vector>

using namespace std;

class Runnable {
public:
    virtual void run() = 0;
};

class One : public Runnable {
private:
    int x;
public:
    One(int x) {
        this->x = x;
    }

    void run() override {
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

    void run() override {
        cout << "Two" << x << endl;
    }
};

vector<Runnable *> a;//此处只能使用指针

int main() {
    One one(1);
    a.push_back(&one);
    auto two = Two("2");
    a.push_back(&two);
    for (auto &i: a) {
        i->run();
    }
    return 0;
}