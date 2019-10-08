LOCAL_PATH := $(call my-dir)

################# helloservice ######################
include $(CLEAR_VARS)

LOCAL_CLANG := true
LOCAL_CFLAGS := -DLOG_TAG=\"HelloService\"

LOCAL_SRC_FILES := \
    main_HelloService.cpp \
    IHelloService.cpp

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    liblog \
    libbinder \
    libutils \
    libdl

LOCAL_MODULE := helloservice

ifdef TARGET_32_BIT_SURFACEFLINGER
LOCAL_32_BIT_ONLY := true
endif

LOCAL_CFLAGS += -Wall -Werror -Wunused -Wunreachable-code

include $(BUILD_EXECUTABLE)

################# helloclient ######################
include $(CLEAR_VARS)

LOCAL_CLANG := true
LOCAL_CFLAGS := -DLOG_TAG=\"HelloClient\"

LOCAL_SRC_FILES := \
    main_HelloClient.cpp \
    IHelloService.cpp

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    liblog \
    libbinder \
    libutils \
    libdl

LOCAL_MODULE := helloclient

ifdef TARGET_32_BIT_SURFACEFLINGER
LOCAL_32_BIT_ONLY := true
endif

LOCAL_CFLAGS += -Wall -Werror -Wunused -Wunreachable-code

include $(BUILD_EXECUTABLE)