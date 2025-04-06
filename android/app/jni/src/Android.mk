LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

# Add your application source files here...
LOCAL_SRC_FILES := ../../../../src/main.cpp ../../../../src/engine.cpp

SDL_PATH := ../SDL

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include  C:/Include/Vulkan-SDK-1.4.309.0/Include

LOCAL_SHARED_LIBRARIES := SDL3

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -lOpenSLES -llog -landroid

include $(BUILD_SHARED_LIBRARY)
