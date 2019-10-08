#ifndef I_HELLO_SERVICE_H
#define I_HELLO_SERVICE_H

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

class IHelloService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(HelloService)
  virtual void hello(const ::android::String16& msg, ::android::String16& reply_msg) = 0;
};  // class IHelloService

class BpHelloService : public ::android::BpInterface<IHelloService> {
public:
  explicit BpHelloService(const ::android::sp<::android::IBinder>& impl);
  virtual ~BpHelloService() = default;
  void hello(const ::android::String16& msg, ::android::String16& reply_msg) override;
};  // class BpHelloService

class BnHelloService : public ::android::BnInterface<IHelloService> {
public:
  ::android::status_t onTransact(uint32_t code, const ::android::Parcel& data, ::android::Parcel* reply, uint32_t flags) override;
  void hello(const ::android::String16& msg, ::android::String16& reply_msg) override;
};  // class BnHelloService

#endif  // I_HELLO_SERVICE_H
