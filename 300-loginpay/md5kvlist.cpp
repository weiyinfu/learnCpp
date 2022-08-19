#include<string>
#include<list>
#include<sstream>
#include "md5/md5.h"

using namespace std;
typedef pair<string, string> KeyValue;

string md5kvlist(list<KeyValue> keyValueList) {
    //将kvlist排序并进行md5签名
    keyValueList.sort();
    bool isFirst = true;
    stringstream o;
    for (const auto &i: keyValueList) {
        if (!isFirst) {
            o << "&";
        } else {
            isFirst = false;
        }
        o << i.first << "=" << httplib::detail::encode_query_param(i.second);
    }
    string sig = MD5(o.str()).toString();
    return sig;
}