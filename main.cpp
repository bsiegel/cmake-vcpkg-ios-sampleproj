#include <iostream>
#include <azure/core.hpp>
#include <azure/storage/blobs.hpp>

using namespace std::string_literals;
using namespace Azure::Storage;
using namespace Azure::Storage::Blobs;

int main() {
  std::cout << "Hello world!" << std::endl;

  auto endpointUrl = "https://mystorageaccount.blob.core.windows.net"s;
  auto accountName = "mystorageaccount"s;
  auto accountKey = "accountsecret"s;

  auto sharedKeyCredential = std::make_shared<StorageSharedKeyCredential>(accountName, accountKey);
  auto blockBlobClient = BlockBlobClient(endpointUrl, sharedKeyCredential);

  std::cout << "Exiting successfully!" << std::endl;

  return 0;
}
