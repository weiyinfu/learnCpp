#pragma once

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/process.hpp>
#include <iostream>
#include <iterator>
#include <regex>
#include <sstream>
#include <string>
#include <vector>
#include <clusterkit/util/common.hpp>

namespace clusterkit {


template<typename T>
inline void print(const T &t) {
    cout << t;
}

// 包中除了最后一个元素之外的其他元素都会调用这个版本的print
template<typename T, typename... Args>
inline void print(const T &t, const Args &... rest) {
    cout << t << " ";  // 打印第一个实参
    print(rest...);    // 递归调用，打印其他实参
}

inline string callSystemCommand(string cmd) {
    boost::process::pstream pio;
    boost::process::system(cmd, boost::process::std_out > pio);
    std::ostringstream o;
    o << pio.rdbuf();
    return o.str();
}

inline

inline pair<int, int> getConsoleWindowSize() {
    auto content = callSystemCommand("/bin/stty size");
    std::stringstream reader(content);
    int w, h;
    reader >> w >> h;
    return std::make_pair(w, h);
}

inline string whoami() {
    string username = callSystemCommand("/usr/bin/whoami");
    boost::trim(username);
    return username;
}

inline int getCpuCount() {
    auto content = callSystemCommand("/usr/bin/lscpu");
    smatch m;
    regex e("CPU\\(s\\):\\s+(\\d+)\n");
    regex_search(content, m, e);
    return boost::lexical_cast<int>(m[1].str());
}

// C++高级技术：move语义+vector追加
template<typename X>
void moveAppend(std::vector<X> &src, std::vector<X> &dst) {
    if (dst.empty()) {
        dst = std::move(src);
    } else {
        dst.reserve(dst.size() + src.size());
        std::move(std::begin(src), std::end(src), std::back_inserter(dst));
        src.clear();
    }
}
};  // namespace clusterkit