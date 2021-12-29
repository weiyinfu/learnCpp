#include <iostream>

#define CPPHTTPLIB_OPENSSL_SUPPORT

#include <httplib.h>

using namespace std;


int main() {
    // HTTPS
    httplib::SSLServer svr;

    svr.Get("/hi", [](const httplib::Request &, httplib::Response &res) {
        res.set_content("Hello World!", "text/plain");
    });

    svr.listen("0.0.0.0", 9966);
    cout << "Hello, World!" << std::endl;
    return 0;
}
