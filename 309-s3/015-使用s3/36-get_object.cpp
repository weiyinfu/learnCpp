#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/GetObjectRequest.h>
#include <fstream>
int main() {
  Aws::SDKOptions options;
  // options.loggingOptions.logLevel = Aws::Utils::Logging::LogLevel::Trace;
  Aws::InitAPI(options);
  std::cout << "creating client" << std::endl;
  // Assign these values before running the program
  const Aws::String bucket_name = "weiyinfu";
  const Aws::String object_name = "haha.txt"; // For demo, set to a text file
  Aws::Client::ClientConfiguration config;

  config.endpointOverride = "http://oss.wh-a.xxxxxxx.cn";
  // Set up the request
  Aws::S3::S3Client s3_client(
      config, Aws::Client::AWSAuthV4Signer::PayloadSigningPolicy::Never, false);
  std::cout << "create client over" << std::endl;
  Aws::S3::Model::GetObjectRequest object_request;
  object_request.SetBucket(bucket_name);
  object_request.SetKey(object_name);

  // Get the object
  auto get_object_outcome = s3_client.GetObject(object_request);
  if (get_object_outcome.IsSuccess()) {
    // Get an Aws::IOStream reference to the retrieved file
    auto &retrieved_file =
        get_object_outcome.GetResultWithOwnership().GetBody();

    // Output the first line of the retrieved text file
    std::cout << "Beginning of file contents:\n";
    char file_data[255] = {0};
    retrieved_file.getline(file_data, 254);
    std::cout << file_data << std::endl;

    // Alternatively, read the object's contents and write to a file
    const char *filename = "out.bin";
    std::ofstream output_file(filename, std::ios::binary);
    output_file << retrieved_file.rdbuf();
  } else {
    auto error = get_object_outcome.GetError();
    std::cout << "ERROR: " << error.GetExceptionName() << ": "
              << error.GetMessage() << std::endl;
  }
  return 0;
}
