#include <clusterkit/util/colorama.hpp>
namespace clusterkit {
const std::string colorama::CSI = "\033[";
const std::string colorama::OSC = "\033]";
const std::string colorama::BEL = "\007";

colorama::AnsiBack colorama::BACK = colorama::AnsiBack();
colorama::AnsiFore colorama::FORE = colorama::AnsiFore();
colorama::AnsiCursor colorama::CURSOR = colorama::AnsiCursor();
colorama::AnsiStyle colorama::STYLE = colorama::AnsiStyle();
} // namespace clusterkit
