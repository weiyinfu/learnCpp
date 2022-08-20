#pragma once

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <boost/lexical_cast.hpp>
#include <clusterkit/util/builtin.hpp>
#include <iostream>
#include <clusterkit/util/common.hpp>
#include <sstream>
#include <string>

namespace clusterkit {
    class tqdm {
        // Input
        int total;                              //总个数
        int progress = -1;                      //当前进度
        ul ncols;                              //控制台进度条宽度
        string desc;                            //进度条描述
        const ll PRINT_INTERVAL_MILLIS = 1000;  //每隔多长时间打印一次
        const string DEFAULT_UNIT_CHAR = "█";
        // State
        ll lastPrintTime = 0;  //上次打印时间
        ll lastProgress{};       //上次的进度
        ll beginTime;          //进度条开始时间
        int lastLength;  //上次打印字符的长度,此次打印字符长度不能小于这个数值,如果小于了,需要使用空格填充

        string unitChar;
        // Default
        const int DEFAULT_NCOLS = 70;

        static void print(const string &s) { std::cout << s << std::flush; }

    public:
        tqdm(int total, const string &desc, int ncols = -1, const string &unitChar = "")
                : total(total), desc(desc), unitChar(unitChar) {
            this->total = total;
            this->desc = desc;
            if (ncols == -1) {
                auto console_size = getConsoleWindowSize();
                this->ncols =
                        console_size.second - desc.size() - 35;  // C++的字符串支持太弱了!
                if (this->ncols <= 0) {
                    this->ncols = DEFAULT_NCOLS;
                }
            } else {
                this->ncols = ncols;
            }
            this->ncols = min(this->ncols, 120ul);
            if (unitChar.empty()) {
                this->unitChar = DEFAULT_UNIT_CHAR;
            }
            this->beginTime = this->lastPrintTime = currentTimeMillis();
            this->lastLength = 0;
        }

        void update(int delta) {
            progress += delta;
            //两次打印时间间隔太短,不再更新
            if (currentTimeMillis() - lastPrintTime < PRINT_INTERVAL_MILLIS) return;

            ll usedTime = currentTimeMillis() - beginTime;
            ll leftTime = (ll) (usedTime * 1.0 / progress * (total - progress));
            char timeString[40];
            timeString[sprintf(
                    timeString, "[%s<%s,%s]", formatTime(usedTime).c_str(),
                    formatTime(leftTime).c_str(),
                    formatSpeed(progress, lastProgress, currentTimeMillis() - lastPrintTime)
                            .c_str())] = 0;  //给timeString添加一个结尾符号
            stringstream builder;
            if (desc.length() > 0) {
                builder << desc << ":";
            }
            // Percent String
            double percent = 1.0 * progress / total * 100;
            builder << (int) (percent) << '%';
            // GuiProgress String
            int charCount = min(progress * ncols / total, this->ncols);
            string chars;
            for (int i = 0; i < charCount; i++) {
                chars += unitChar;
            }
            for (unsigned long i = charCount; i <= ncols; i++) {
                chars += ' ';
            }
            builder << '|' << chars << '|';
            builder << progress << '/' << total << timeString;
            string s;
            getline(builder, s);
            int currentLength = s.length();
            //此次打印长度不能小于上次打印长度
            for (int i = currentLength; i < lastLength; i++) {
                s += ' ';
            }
            lastLength = currentLength;
            print(string("\r") + s);

            lastPrintTime = currentTimeMillis();
            lastProgress = progress;
        }

        static string formatTime(ll duration) {
            const int SECOND = 1000;
            const int MINUTE = 60 * SECOND;
            const int HOUR = 60 * MINUTE;
            const int DAY = 24 * HOUR;
            ll day = duration / DAY;
            duration %= DAY;
            ll hour = duration / HOUR;
            duration %= HOUR;
            ll minute = duration / MINUTE;
            duration %= MINUTE;
            ll second = duration / SECOND;
            stringstream builder;
            if (day > 0) {
                builder << day << 'd';
            }
            if (hour > 0) {
                builder << hour << "H";
            }
            if (minute > 0) {
                builder << minute << "m";
            }
            if (second > 0) {
                builder << second << "s";
            }
            string s;
            builder >> s;
            return s;
        }

        static string formatSpeed(ll currentProgress, ll lastProgress, ll duration) {
            ll progress = currentProgress - lastProgress;
            if (progress == 1) {
                return formatTime(duration) + "/iter";
            } else {
                return std::to_string(progress) + " iter/s";
            }
        }
    };
} // namespace clusterkit