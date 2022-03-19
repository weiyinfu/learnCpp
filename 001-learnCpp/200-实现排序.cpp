#include <iostream>
#include<random>
#include<vector>
#include <chrono>
#include <cstdlib>

using namespace std;

class Node {
public:
    int x;

    Node(int x) {
        this->x = x;
    }

    friend bool operator<(const Node &b, const Node &a) {
        return b.x < a.x;
    }
};

void show(vector<Node> &a) {
    for (auto &i: a) {
        cout << i.x << ",";
    }
    cout << endl;
}

int cmp(const void *x, const void *y) {
    auto xx = (Node *) x;
    auto yy = (Node *) y;
    return xx->x - yy->x;
}

int main() {
    vector<Node> a;
    for (int i = 0; i < 10; i++) {
        a.emplace_back(random() % 100);
    }
    std::sort(a.begin(), a.end());
    show(a);
//    auto g = default_random_engine(time(nullptr));
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto g = default_random_engine(seed);
    shuffle(a.begin(), a.end(), g);
    show(a);
    qsort(&a[0], a.size(), sizeof a[0], cmp);
    show(a);
    //再次打乱
    shuffle(a.begin(), a.end(), g);
    qsort(a.data(), a.size(), sizeof a[0], cmp);
    show(a);
    return 0;
}