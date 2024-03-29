// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "Mine.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::two;

class MineHandler : virtual public MineIf {
 public:
  MineHandler() {
    // Your initialization goes here
  }

  void Get(User& _return, const User& user) {
    // Your implementation goes here
    printf("Get\n");
  }

  void Get2(const User& user) {
    // Your implementation goes here
    printf("Get2\n");
  }

  void Get3(User& _return) {
    // Your implementation goes here
    printf("Get3\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<MineHandler> handler(new MineHandler());
  ::std::shared_ptr<TProcessor> processor(new MineProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

