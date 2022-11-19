#include <regex>
#include <iostream>

using namespace std;

/**
 * https://p26-passport.byteacctimg.com/img/user-avatar/84a38c7c0574397b0fa07cc0a44ca8ab.png~128x128.image

https://p26-passport.byteacctimg.com/img/user-avatar/84a38c7c0574397b0fa07cc0a44ca8ab.png~300x300.image
 * */
int main() {
    string raw = "https://p26-passport.byteacctimg.com/img/user-avatar/84a38c7c0574397b0fa07cc0a44ca8ab.png~300x300.image";
    std::smatch m;
    std::regex e("~\\d+x\\d+.image$");
    if (std::regex_search(raw, m, e, regex_constants::match_default)) {
        cout << m[0] << endl;
        auto ans = raw.substr(0, raw.size() - m[0].length()) + "~128x128.image";
        cout << ans << endl;
    }
    return 0;
}