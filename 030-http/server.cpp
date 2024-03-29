#include <iostream>
#include <thread>
//#define CPPHTTPLIB_OPENSSL_SUPPORT

#include <httplib.h>

using namespace std;

int main() {
    // HTTP
    httplib::Server svr;

    // HTTPS
    // httplib::SSLServer svr;
    svr.Get("/hi", [](const httplib::Request &, httplib::Response &res) {
        this_thread::sleep_for(chrono::seconds(1));
        res.set_content("Hello World!", "text/plain");
    });

    svr.listen("0.0.0.0", 9978);
    cout << "Hello, World!" << std::endl;
    return 0;
}
