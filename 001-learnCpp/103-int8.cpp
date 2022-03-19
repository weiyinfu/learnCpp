#include<iostream>
#include<climits>
#include<cstdint>

using namespace std;

int main() {
    int8_t x = 127;
    int64_t y = 12334;
    int32_t z = 23434;
    uint8_t q = 213;
    cout << INT_MAX//来自climits
         << INT8_MAX << INT64_MAX << endl;
}