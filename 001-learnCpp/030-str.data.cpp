#include <iostream>

using namespace std;

#define enum_to_string(x) #x

enum sex {
    boy,
    girl,
};

int main() {
    string s("haha");
    const char *data = s.data();
    char *a = const_cast<char *>(data);
    a[0] = 'H';
    cout << s << endl;
    cout << enum_to_string(boy) << endl;//boy
    cout << enum_to_string(sex::boy) << endl;//sex::boy
    cout << enum_to_string(bagayalu) << endl;//bagayalu
    return 0;
}