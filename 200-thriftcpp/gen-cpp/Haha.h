/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Haha_H
#define Haha_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "main_types.h"



#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class HahaIf {
 public:
  virtual ~HahaIf() {}
  virtual void haha(std::string& _return, const std::string& s) = 0;
  virtual int32_t baga(const int32_t one, const int32_t two) = 0;
};

class HahaIfFactory {
 public:
  typedef HahaIf Handler;

  virtual ~HahaIfFactory() {}

  virtual HahaIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(HahaIf* /* handler */) = 0;
};

class HahaIfSingletonFactory : virtual public HahaIfFactory {
 public:
  HahaIfSingletonFactory(const ::std::shared_ptr<HahaIf>& iface) : iface_(iface) {}
  virtual ~HahaIfSingletonFactory() {}

  virtual HahaIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(HahaIf* /* handler */) {}

 protected:
  ::std::shared_ptr<HahaIf> iface_;
};

class HahaNull : virtual public HahaIf {
 public:
  virtual ~HahaNull() {}
  void haha(std::string& /* _return */, const std::string& /* s */) {
    return;
  }
  int32_t baga(const int32_t /* one */, const int32_t /* two */) {
    int32_t _return = 0;
    return _return;
  }
};

typedef struct _Haha_haha_args__isset {
  _Haha_haha_args__isset() : s(false) {}
  bool s :1;
} _Haha_haha_args__isset;

class Haha_haha_args {
 public:

  Haha_haha_args(const Haha_haha_args&);
  Haha_haha_args& operator=(const Haha_haha_args&);
  Haha_haha_args() : s() {
  }

  virtual ~Haha_haha_args() noexcept;
  std::string s;

  _Haha_haha_args__isset __isset;

  void __set_s(const std::string& val);

  bool operator == (const Haha_haha_args & rhs) const
  {
    if (!(s == rhs.s))
      return false;
    return true;
  }
  bool operator != (const Haha_haha_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Haha_haha_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Haha_haha_pargs {
 public:


  virtual ~Haha_haha_pargs() noexcept;
  const std::string* s;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Haha_haha_result__isset {
  _Haha_haha_result__isset() : success(false) {}
  bool success :1;
} _Haha_haha_result__isset;

class Haha_haha_result {
 public:

  Haha_haha_result(const Haha_haha_result&);
  Haha_haha_result& operator=(const Haha_haha_result&);
  Haha_haha_result() : success() {
  }

  virtual ~Haha_haha_result() noexcept;
  std::string success;

  _Haha_haha_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const Haha_haha_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Haha_haha_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Haha_haha_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Haha_haha_presult__isset {
  _Haha_haha_presult__isset() : success(false) {}
  bool success :1;
} _Haha_haha_presult__isset;

class Haha_haha_presult {
 public:


  virtual ~Haha_haha_presult() noexcept;
  std::string* success;

  _Haha_haha_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Haha_baga_args__isset {
  _Haha_baga_args__isset() : one(false), two(false) {}
  bool one :1;
  bool two :1;
} _Haha_baga_args__isset;

class Haha_baga_args {
 public:

  Haha_baga_args(const Haha_baga_args&);
  Haha_baga_args& operator=(const Haha_baga_args&);
  Haha_baga_args() : one(0), two(0) {
  }

  virtual ~Haha_baga_args() noexcept;
  int32_t one;
  int32_t two;

  _Haha_baga_args__isset __isset;

  void __set_one(const int32_t val);

  void __set_two(const int32_t val);

  bool operator == (const Haha_baga_args & rhs) const
  {
    if (!(one == rhs.one))
      return false;
    if (!(two == rhs.two))
      return false;
    return true;
  }
  bool operator != (const Haha_baga_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Haha_baga_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Haha_baga_pargs {
 public:


  virtual ~Haha_baga_pargs() noexcept;
  const int32_t* one;
  const int32_t* two;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Haha_baga_result__isset {
  _Haha_baga_result__isset() : success(false) {}
  bool success :1;
} _Haha_baga_result__isset;

class Haha_baga_result {
 public:

  Haha_baga_result(const Haha_baga_result&);
  Haha_baga_result& operator=(const Haha_baga_result&);
  Haha_baga_result() : success(0) {
  }

  virtual ~Haha_baga_result() noexcept;
  int32_t success;

  _Haha_baga_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const Haha_baga_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Haha_baga_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Haha_baga_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Haha_baga_presult__isset {
  _Haha_baga_presult__isset() : success(false) {}
  bool success :1;
} _Haha_baga_presult__isset;

class Haha_baga_presult {
 public:


  virtual ~Haha_baga_presult() noexcept;
  int32_t* success;

  _Haha_baga_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class HahaClient : virtual public HahaIf {
 public:
  HahaClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  HahaClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void haha(std::string& _return, const std::string& s);
  void send_haha(const std::string& s);
  void recv_haha(std::string& _return);
  int32_t baga(const int32_t one, const int32_t two);
  void send_baga(const int32_t one, const int32_t two);
  int32_t recv_baga();
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class HahaProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<HahaIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (HahaProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_haha(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_baga(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  HahaProcessor(::std::shared_ptr<HahaIf> iface) :
    iface_(iface) {
    processMap_["haha"] = &HahaProcessor::process_haha;
    processMap_["baga"] = &HahaProcessor::process_baga;
  }

  virtual ~HahaProcessor() {}
};

class HahaProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  HahaProcessorFactory(const ::std::shared_ptr< HahaIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< HahaIfFactory > handlerFactory_;
};

class HahaMultiface : virtual public HahaIf {
 public:
  HahaMultiface(std::vector<std::shared_ptr<HahaIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~HahaMultiface() {}
 protected:
  std::vector<std::shared_ptr<HahaIf> > ifaces_;
  HahaMultiface() {}
  void add(::std::shared_ptr<HahaIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void haha(std::string& _return, const std::string& s) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->haha(_return, s);
    }
    ifaces_[i]->haha(_return, s);
    return;
  }

  int32_t baga(const int32_t one, const int32_t two) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->baga(one, two);
    }
    return ifaces_[i]->baga(one, two);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class HahaConcurrentClient : virtual public HahaIf {
 public:
  HahaConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  HahaConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void haha(std::string& _return, const std::string& s);
  int32_t send_haha(const std::string& s);
  void recv_haha(std::string& _return, const int32_t seqid);
  int32_t baga(const int32_t one, const int32_t two);
  int32_t send_baga(const int32_t one, const int32_t two);
  int32_t recv_baga(const int32_t seqid);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif



#endif