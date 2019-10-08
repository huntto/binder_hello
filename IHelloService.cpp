#include "IHelloService.h"
#include <binder/Parcel.h>

IMPLEMENT_META_INTERFACE(HelloService, "IHelloService")

BpHelloService::BpHelloService(const ::android::sp<::android::IBinder>& impl)
    : BpInterface<IHelloService>(impl){
}

void BpHelloService::hello(const ::android::String16& msg, ::android::String16& reply_msg) {
  ::android::Parcel data;
  ::android::Parcel reply;

  ::android::status_t ret_status = ::android::OK;

  ret_status = data.writeInterfaceToken(getInterfaceDescriptor());
  if (((ret_status) != (::android::OK))) {
    goto error;
  }

  ret_status = data.writeString16(msg);
  if (((ret_status) != (::android::OK))) {
    goto error;
  }

  ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* hello */, data, &reply);
  if (((ret_status) != (::android::OK))) {
    goto error;
  }

  ret_status = reply.readString16(&reply_msg);
  if (((ret_status) != (::android::OK))) {
    goto error;
  }

  return;

  error:
    printf("hello error:%d\n", ret_status);
}

::android::status_t BnHelloService::onTransact(uint32_t code, const ::android::Parcel& data, ::android::Parcel* reply, uint32_t flags) {
  ::android::status_t ret_status = ::android::OK;

  switch (code) {
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* hello */:
  {
    ::android::String16 msg;
    ::android::String16 reply_msg;

    if (!(data.checkInterface(this))) {
      ret_status = ::android::BAD_TYPE;
      break;
    }

    ret_status = data.readString16(&msg);
    if (((ret_status) != (::android::OK))) {
      break;
    }

    hello(msg, reply_msg);

    ret_status = reply->writeString16(reply_msg);
    if (((ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  default:
  {
    ret_status = ::android::BBinder::onTransact(code, data, reply, flags);
  }
  break;
  }
  if (ret_status == ::android::UNEXPECTED_NULL) {
    ret_status = ::android::binder::Status::fromExceptionCode(::android::binder::Status::EX_NULL_POINTER).writeToParcel(reply);
  }
  return ret_status;
}

void BnHelloService::hello(const ::android::String16& msg, ::android::String16& reply_msg) {
  using namespace android;
  printf("Service got msg: %s\n", String8(msg).string());
  reply_msg = String16("Hi, I'm the Service!");
  printf("Service reply msg: %s\n", String8(reply_msg).string());
}