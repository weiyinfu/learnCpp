#pragma once

#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/process.hpp>
#include <boost/system/error_code.hpp>
#include <clusterkit/util/builtin.hpp>
#include <iostream>
#include <string>
#include <vector>
#include<clusterkit/util/common.hpp>

namespace clusterkit {
    class net {

    public:
        static vector<std::string> domain2ip(const char *domain, int port = -1) {
            /**
             * 把域名转化成IP地址
             * */
            boost::asio::io_service ios;

            boost::asio::ip::tcp::resolver resolver(ios); //创建resolver对象
            //创建query对象
            boost::asio::ip::tcp::resolver::query query(
                    domain,
                    std::to_string(port)); //将int型端口转换为字符串
            //使用resolve迭代端点
            boost::asio::ip::tcp::resolver::iterator end;
            vector<string> ip;
            for (boost::asio::ip::tcp::resolver::iterator it = resolver.resolve(query);
                 it != end; it++) {
                ip.push_back(it->endpoint().address().to_string());
            }
            return ip;
        }

        static string getHostName() {
            /*
             * 获取本机的主机名
             * */
            string hostName = callSystemCommand("/bin/hostname -f");
            boost::trim(hostName);
            return hostName;
        }
    };
}; // namespace clusterkit