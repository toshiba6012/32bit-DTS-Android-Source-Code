LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := dcaenc
LOCAL_C_INCLUDES := alsa
LOCAL_CFLAGS := -std=gnu89

LOCAL_SRC_FILES := \
		dcaenc.c \
		math_tables.c \
		alsaplugin.c
			
LOCAL_ALLOW_UNDEFINED_SYMBOLS := true

include $(BUILD_SHARED_LIBRARY)
		