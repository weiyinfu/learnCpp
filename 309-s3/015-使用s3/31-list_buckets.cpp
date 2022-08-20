#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/Bucket.h>
#include <aws/s3/model/ListObjectsRequest.h>
#include <iostream>
int main() {
  Aws::SDKOptions options;
  // options.loggingOptions.logLevel = Aws::Utils::Logging::LogLevel::Trace;
  Aws::InitAPI(options);
  std::cout << "creating client" << std::endl;
  Aws::Client::ClientConfiguration config;
  {
    config.endpointOverride = "http://oss.xxx.xxxxx.cn";
    auto client = Aws::S3::S3Client(config);
    std::cout << "outcome is reached";
    auto outcome = client.ListBuckets();
    if (outcome.IsSuccess()) {
      std::cout << "Your Amazon S3 buckets:" << std::endl;

      Aws::Vector<Aws::S3::Model::Bucket> bucket_list =
          outcome.GetResult().GetBuckets();

      for (auto const &bucket : bucket_list) {
        std::cout << "* " << bucket.GetName() << std::endl;
      }
    } else {
      std::cout << "ListBuckets error: "
                << outcome.GetError().GetExceptionName() << " - "
                << outcome.GetError().GetMessage() << std::endl;
    }
  }
  Aws::ShutdownAPI(options);
}