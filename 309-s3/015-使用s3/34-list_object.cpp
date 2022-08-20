#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/ListObjectsRequest.h>
#include <aws/s3/model/Object.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int main() {
  Aws::SDKOptions options;
  options.loggingOptions.logLevel = Aws::Utils::Logging::LogLevel::Trace;
  Aws::InitAPI(options);
  Aws::Client::ClientConfiguration config;
  config.endpointOverride = "http://oss.wh-a.xxxxx.cn";
  // config.scheme = Aws::Http::Scheme::HTTP;
  config.verifySSL = false;
  config.connectTimeoutMs = 300000;
  config.requestTimeoutMs = 600000;
  Aws::S3::S3Client client(
      config, Aws::Client::AWSAuthV4Signer::PayloadSigningPolicy::Never, false);
  Aws::String bucketName = "";
  Aws::S3::Model::ListObjectsRequest req;
  req.SetBucket("cluster-dataset");
  req.SetPrefix("mixin");
  cout << "before request" << endl;
  auto list_objects_outcome = client.ListObjects(req);
  cout << "after request" << endl;
  if (list_objects_outcome.IsSuccess()) {
    std::cout << "success" << std::endl;
    Aws::Vector<Aws::S3::Model::Object> object_list =
        list_objects_outcome.GetResult().GetContents();

    for (auto const &s3_object : object_list) {
      std::cout << "* " << s3_object.GetKey() << std::endl;
    }
  } else {
    std::cout << "ListObjects error: "
              << list_objects_outcome.GetError().GetExceptionName() << " "
              << list_objects_outcome.GetError().GetMessage() << std::endl;
  }
  return 0;
}
