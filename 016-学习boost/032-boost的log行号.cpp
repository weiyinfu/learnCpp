#include <boost/filesystem.hpp>
#include <boost/log/core.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/manipulators/add_value.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <fstream>
#include <ostream>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace sinks = boost::log::sinks;

void my_formatter(logging::record_view const& rec,
                  logging::formatting_ostream& strm) {
  // Get the LineID attribute value and put it into the stream
  strm << logging::extract<unsigned int>("LineID", rec) << ": ";
  strm << logging::extract<int>("Line", rec) << ": ";
  logging::value_ref<std::string> fullpath =
      logging::extract<std::string>("File", rec);
  strm << boost::filesystem::path(fullpath.get()).filename().string() << ": ";

  // The same for the severity level.
  // The simplified syntax is possible if attribute keywords are used.
  strm << "<" << rec[logging::trivial::severity] << "> ";

  // Finally, put the record message to the stream
  strm << rec[expr::smessage];
}

void init() {
  typedef sinks::synchronous_sink<sinks::text_ostream_backend> text_sink;
  boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();

  sink->locked_backend()->add_stream(
      boost::make_shared<std::ofstream>("sample.log"));

  sink->set_formatter(&my_formatter);

  logging::core::get()->add_sink(sink);
}

#define MY_GLOBAL_LOGGER(log_, sv)                                   \
  BOOST_LOG_SEV(log_, sv) << boost::log::add_value("Line", __LINE__) \
                          << boost::log::add_value("File", __FILE__) \
                          << boost::log::add_value("Function",       \
                                                   BOOST_CURRENT_FUNCTION)

int main(int, char* []) {
  init();
  logging::add_common_attributes();

  using namespace logging::trivial;
  src::severity_logger<severity_level> lg;

  MY_GLOBAL_LOGGER(lg, debug) << "Keep";
  MY_GLOBAL_LOGGER(lg, info) << "It";
  MY_GLOBAL_LOGGER(lg, warning) << "Simple";
  MY_GLOBAL_LOGGER(lg, error) << "Stupid";

  return 0;
}