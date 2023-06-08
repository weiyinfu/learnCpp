#include<nlohmann/json.hpp>
#include <iostream>

using namespace std;

int main() {
    auto s = "{\"addition\": {\"duration\": \"2580\",\"has_speech\": \"true\",\"logid\": \"202306052046399B31293D4CE5A644A59F\",\"split_time\": \"[]\",\"termination\": \"true\"},\"code\": 1000,\"message\": \"Success\",\"reqid\": \"f1213d0f-af54-4e1e-b955-21f3235311d4\",\"result\": [{\"confidence\": 0,\"text\": \"五六七八\"}],\"sequence\": 28}";
    auto ss = "{\"addition\": {\"duration\": \"2580\",\"has_speech\": \"true\",\"logid\": \"202306052046399B31293D4CE5A644A59F\",\"split_time\": \"[]\",\"termination\": \"true\"},\"code\": 1000,\"message\": \"Success\",\"reqid\": \"f1213d0f-af54-4e1e-b955-21f3235311d4\",\"sequence\": 28}";
    nlohmann::json jsonData = nlohmann::json::parse(ss);
    std::string sessionId = jsonData["reqid"];
    bool isFinal = false;
    auto result = jsonData["result"];
    if (result.size() > 0) {
        auto first = result[0];
        std::string text = first["text"];
        cout << "text " << text << endl;
    }
    cout << "sessionID " << sessionId << endl;
    return 0;
}