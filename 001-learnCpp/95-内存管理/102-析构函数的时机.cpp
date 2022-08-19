#include<iostream>

using namespace std;

struct Node {
    int a;

    Node(int x) {
        a = x;
    }

    ~Node() {
        cout << "node is deleted:" << a << endl;
    }
};

void handle() {
    Node x = Node(3);
    x = Node(4);
    cout << x.a << endl;
}

int main() {
    handle();
    cout << "handle is done" << endl;
    return 0;
}