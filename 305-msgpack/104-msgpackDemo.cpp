#include <msgpack.hpp>
#include <vector>
#include <string>
#include <iostream>

int main() {
    std::vector<std::string> _vecString;
    _vecString.emplace_back("Hello");
    _vecString.emplace_back("world");

    // pack
    msgpack::sbuffer _sbuffer;
    msgpack::pack(_sbuffer, _vecString);
    std::cout << _sbuffer.data() << std::endl;

    // unpack
    auto obj = msgpack::unpack(_sbuffer.data(), _sbuffer.size());
    std::cout << obj.get() << std::endl;

    // convert
    std::vector<std::string> _vecRString = obj->convert();

    // print
    for (size_t i = 0; i < _vecRString.size(); ++i) {
        std::cout << _vecRString[i] << std::endl;
    }

    return 0;
}