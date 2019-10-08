#include "IHelloService.h"

#include <binder/IServiceManager.h>

int main() {
  using namespace android;
  sp<IServiceManager> sm = defaultServiceManager();
  sp<IBinder> binder = sm->getService(IHelloService::descriptor);
  sp<IHelloService> service = interface_cast <IHelloService> (binder);

  String16 reply_msg;
  String16 msg("Hello, I'm a Client");

  printf("Client send msg: %s\n", String8(msg).string());
  service->hello(String16("Hello, I'm a Client."), reply_msg);
  printf("Client got reply msg: %s\n", String8(reply_msg).string());

  return 0;
}