#pragma once

#include <boost/lexical_cast.hpp>
#include <string>

namespace clusterkit {
class colorama {
  static const std::string CSI, OSC, BEL;

  static std::string codeToChars(const std::string &code) { return CSI + code + "m"; }

  static std::string str(int x) { return std::to_string(x); }

  static std::string join(const std::string &a, int b, const std::string &c) {
      return a + str(b) + c;
  }

  static std::string wrap(const std::string &code) { return CSI + code + 'm'; }

public:
  static std::string setTitle(const std::string &title) {
      return OSC + "2;" + title + BEL;
  }

  static std::string clearScreen(int mode = -1) {
      if (mode == -1)
          mode = 2;
      return CSI + std::to_string(mode) + "J";
  }

  static std::string clearLine(int mode = -1) {
      if (mode == -1)
          mode = 2;
      return CSI + std::to_string(mode) + "K";
  }

  class AnsiCursor {
  public:
    static std::string up(int n) { return join(CSI, n, "A"); }

    static std::string down(int n) { return join(CSI, n, "B"); }

    static std::string forward(int n) { return join(CSI, n, "C"); }

    static std::string back(int n) { return join(CSI, n, "D"); }

    static std::string pos(int x, int y) { return CSI + str(y) + ";" + str(x) + "H"; }
  };

  class AnsiFore {
  public:
    std::string BLACK = wrap("30"), RED = wrap("31"), GREEN = wrap("32"),
            YELLOW = wrap("33"), BLUE = wrap("34"), MAGENTA = wrap("35"),
            CYAN = wrap("36"), WHITE = wrap("37"), RESET = wrap("39");
    // These are fairly well supported, but not part of the standard.
    std::string LIGHTBLACK_EX = wrap("90"), LIGHTRED_EX = wrap("91"),
            LIGHTGREEN_EX = wrap("92"), LIGHTYELLOW_EX = wrap("93"),
            LIGHTBLUE_EX = wrap("94"), LIGHTMAGENTA_EX = wrap("95"),
            LIGHTCYAN_EX = wrap("96"), LIGHTWHITE_EX = wrap("97");
  };

  class AnsiBack {
  public:
    std::string BLACK = wrap("40"), RED = wrap("41"), GREEN = wrap("42"),
            YELLOW = wrap("43"), BLUE = wrap("44"), MAGENTA = wrap("45"),
            CYAN = wrap("46"), WHITE = wrap("47"), RESET = wrap("49");

    // These are fairly well supported, but not part of the standard.
    std::string LIGHTBLACK_EX = wrap("100"), LIGHTRED_EX = wrap("101"),
            LIGHTGREEN_EX = wrap("102"), LIGHTYELLOW_EX = wrap("103"),
            LIGHTBLUE_EX = wrap("104"), LIGHTMAGENTA_EX = wrap("105"),
            LIGHTCYAN_EX = wrap("106"), LIGHTWHITE_EX = wrap("107");
  };

  class AnsiStyle {
  public:
    std::string BRIGHT = wrap("1"), DIM = wrap("2"), NORMAL = wrap("22"),
            RESET_ALL = wrap("0");
  };

public:
  static AnsiFore FORE;
  static AnsiBack BACK;
  static AnsiStyle STYLE;
  static AnsiCursor CURSOR;
};

} // namespace clusterkit