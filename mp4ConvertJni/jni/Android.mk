
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm
LOCAL_C_INCLUDES += $(FFMPEG_PATH)		
LOCAL_CFLAGS := $(PLAYER_CFLAGS)
LOCAL_CFLAGS += $(ARMV7_OPTION)
LOCAL_LDFLAGS += -Wl
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -L$(LOCAL_PATH) -llog -lz -ldl  -lm
	

LOCAL_MODULE    := Mp4Transcode

LOCAL_SRC_FILES := \
									Mp4Transcode.c \
									RecorderJni.c

include $(BUILD_SHARED_LIBRARY)
