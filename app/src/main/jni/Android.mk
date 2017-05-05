LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_LDLIBS := -lm -llog
LOCAL_MODULE := dsaa
LOCAL_SRC_FILES += ./linearList/SqList.c
LOCAL_SRC_FILES += ./Provider.c

include $(BUILD_SHARED_LIBRARY)
