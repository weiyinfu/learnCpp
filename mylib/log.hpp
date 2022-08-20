#include <boost/log/trivial.hpp>
// http://www.wanguanglu.com/2016/07/28/boost-log-document/
#define LOG(x)                                                                 \
  BOOST_LOG_TRIVIAL(x) << __FILE__ << ':' << __LINE__ << ' ' << (__FUNCTION__) \
                       << ' '
