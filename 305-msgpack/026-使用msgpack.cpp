#include <fstream>
#include <iostream>
#include <msgpack.hpp>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void testMsgpack() {
    msgpack::type::tuple<int, bool, std::string> src(1, true, "example");

    // serialize the object into the buffer.
    // any classes that implements write(const char*,size_t) can be a buffer.
    std::stringstream buffer;
    msgpack::pack(buffer, src);

    // send the buffer ...
    buffer.seekg(0);

    // deserialize the buffer into msgpack::object instance.
    std::string str(buffer.str());

    msgpack::object_handle oh = msgpack::unpack(str.data(), str.size());
    // deserialized object is valid during the msgpack::object_handle instance is
    // alive.
    msgpack::object deserialized = oh.get();

    // msgpack::object supports ostream.
    std::cout << deserialized << std::endl;

    // convert msgpack::object instance into the original type.
    // if the type is mismatched, it throws msgpack::type_error exception.
    msgpack::type::tuple<int, bool, std::string> dst;
    deserialized.convert(dst);

    // or create the new instance
    msgpack::type::tuple<int, bool, std::string> dst2 =deserialized.as<msgpack::type::tuple<int, bool, std::string>>();
}

msgpack::object_handle why() {
    msgpack::type::tuple<int, bool, std::string> src(1, true, "example");

    // serialize the object into the buffer.
    // any classes that implements write(const char*,size_t) can be a buffer.
    std::stringstream buffer;
    msgpack::pack(buffer, src);

    // send the buffer ...
    buffer.seekg(0);

    // deserialize the buffer into msgpack::object instance.
    std::string str(buffer.str());

    msgpack::object_handle oh = msgpack::unpack(str.data(), str.size());
    return oh;
}

vector<msgpack::object_handle> whywhy() {
    //这样无法运行
    vector<msgpack::object_handle> a;
    for (int i = 0; i < 10; i++) {
        msgpack::type::tuple<int, bool, std::string> src(1, true, "example");

        // serialize the object into the buffer.
        // any classes that implements write(const char*,size_t) can be a buffer.
        std::stringstream buffer;
        msgpack::pack(buffer, src);

        // send the buffer ...
        buffer.seekg(0);

        // deserialize the buffer into msgpack::object instance.
        std::string str(buffer.str());

        msgpack::object_handle oh = msgpack::unpack(str.data(), str.size());
        a.push_back(std::move(oh));  //此处必须加上移动语义，否则无法运行
    }
    return a;
}

vector<msgpack::object_handle> whywhywhy() {
    //这样无法运行
    vector<msgpack::object_handle> a;
    for (int i = 0; i < 10; i++) {
        a.push_back(why());
    }
    return a;
}

int main() {
    // testMsgpack();
    // msgpack::object_handle x = why();
    // cout << x.get() << endl;
    for (auto &i: whywhy()) {
        cout << i.get() << endl;
    }
    return 0;
}
