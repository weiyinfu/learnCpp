#include <msgpack.hpp>
#include <vector>
#include <string>
#include<iostream>

using namespace std;

class my_class {
public:
    string my_string;
    vector<int> vec_int;
    vector<string> vec_string;
    MSGPACK_DEFINE (my_string, vec_int, vec_string);
};

int main() {
    std::vector<my_class> my_class_vec;
    my_class x;
    x.my_string = "weiyinfu";
    x.vec_int.push_back(1);
    x.vec_string.emplace_back("one");
    my_class_vec.emplace_back(x);
    msgpack::sbuffer buffer;
    msgpack::pack(buffer, my_class_vec);
    msgpack::unpacked msg;
    auto obj = msgpack::unpack(buffer.data(), buffer.size());
    std::vector<my_class> my_class_vec_r = obj->convert();
    cout << my_class_vec_r.size() << endl;
    for (auto i = 0; i < my_class_vec_r.size(); i++) {
        auto x = my_class_vec_r[i];
        cout << x.my_string << ";" << x.vec_int.size() << ";" << x.vec_string.size() << endl;
    }
    return 0;
}