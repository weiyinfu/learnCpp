#include<iostream>

//#define CPPHTTPLIB_OPENSSL_SUPPORT

#include <httplib.h>

using namespace std;

int main() {

// HTTP
    httplib::Client cli("http://localhost:9966");

// HTTPS
//    httplib::Client cli("https://cpp-httplib-server.yhirose.repl.co");

    auto res = cli.Get("/hi");
    cout << res->status;
    cout << res->body;
    return 0;
}