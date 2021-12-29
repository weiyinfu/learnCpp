#include <boost/lexical_cast.hpp>
#include <iostream>

using namespace std;
using namespace boost;

int main() {
    double x = 3;
    cout << lexical_cast<string>(x) << endl;
    cout << lexical_cast<double>("3.478") << endl;
    int i;
    try {
        i = boost::lexical_cast<int>("abcd");
    } catch (boost::bad_lexical_cast &e) {
        cout << e.what() << endl;
    }
    // lexical_cast的原理
    int d;
    std::stringstream s;
    s << "123";
    s >> d;
    cout << d << endl;
    return 0;
}