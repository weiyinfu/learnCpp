#include <cstdlib>
#include <cstdio>
#include<iostream>

using namespace std;

class Haha {
public:
    void *operator new(size_t size) {
        if (void *mem = malloc(size)) {
            return mem;
        }
        throw bad_alloc();
    };

    void operator delete(void *mem) noexcept {
        free(mem);
    };
};

int main() {
    Haha *x = new Haha();
    return 0;
}