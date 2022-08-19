#include <string>
#include <algorithm>
#include <cctype>
#include "url.h"
#include<vector>
#include <functional>

using namespace std;

Url parse_url(const string &url_s) {
    const string prot_end("://");
    string::const_iterator prot_i = search(url_s.begin(), url_s.end(),
                                           prot_end.begin(), prot_end.end());
    Url ans;
    ans.protocol.reserve(distance(url_s.begin(), prot_i));
    transform(url_s.begin(), prot_i,
              back_inserter(ans.protocol),
              ptr_fun<int, int>(tolower)); // protocol is icase
    if (prot_i == url_s.end())
        return ans;
    advance(prot_i, prot_end.length());
    string::const_iterator path_i = find(prot_i, url_s.end(), '/');
    ans.host.reserve(distance(prot_i, path_i));
    transform(prot_i, path_i,
              back_inserter(ans.host),
              ptr_fun<int, int>(tolower)); // host is icase
    string::const_iterator query_i = find(path_i, url_s.end(), '?');
    ans.path.assign(path_i, query_i);
    if (query_i != url_s.end()) {
        ++query_i;
    }
    ans.query.assign(query_i, url_s.end());
    ans.origin = ans.protocol + "://" + ans.host;
    return ans;
}
