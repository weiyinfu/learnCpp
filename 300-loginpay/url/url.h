#ifndef URL_HH_
#define URL_HH_

#include <string>

struct Url {
    std::string protocol;
    std::string host;
    std::string path;
    std::string query;
    std::string origin;
};

Url parse_url(const std::string &url_s);

#endif /* URL_HH_ */