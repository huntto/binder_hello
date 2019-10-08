#include "IHelloService.h"

#include <binder/IServiceManager.h>
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>

int main() {
  using namespace android;
  sp<IServiceManager> sm = defaultServiceManager();
  sm->addService(IHelloService::descriptor, new BnHelloService());
  ProcessState::self()->startThreadPool();
  IPCThreadState::self()->joinThreadPool();
  return 0;
}