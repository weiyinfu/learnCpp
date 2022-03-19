#include<iostream>

using namespace std;

class Animal {
    virtual void shout() = 0;

    virtual void run() = 0;
};

class Dog : public Animal {
    void shout() override {
        cout << "dog shout" << endl;
    }

    void run() override {
        cout << "dog run" << endl;
    }
};

class Cat : public Animal {
    void shout() override {
        cout << "cat shout" << endl;
    }

    void run() override {
        cout << "cat run" << endl;
    }
};

int main() {

    return 0;
}