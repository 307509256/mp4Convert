APP_PLATFORM := android-10
APP_ABI := armeabi armeabi-v7a
APP_OPTIM := release
OPT_CFLAGS := -O3
OPT_CPPFLAGS := $(OPT_CFLAGS)
APP_CFLAGS := $(APP_CFLAGS) $(OPT_CFLAGS)
#APP_CPPFLAGS := $(APP_CPPFLAGS) $(OPT_CPPFLAGS)
APP_STL := gnustl_static

PLAYER_CFLAGS += -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE

#for htc g8:
#ARMV6_OPTION := -DHAVE_NEON=0 -march=armv6

ARMV5_OPTION := -DHAVE_NEON=0 -march=armv5

ARMV6_OPTION := -DHAVE_NEON=0 -march=armv6 -mfloat-abi=softfp -mfpu=vfp

ARMV7_OPTION := -DHAVE_NEON=0 -march=armv7-a -mfpu=vfp -mfloat-abi=softfp

ARMV7NEON_OPTION := -DHAVE_NEON=1 -march=armv7-a -mfpu=neon -mfloat-abi=softfp -ftree-vectorize -fvect-cost-model -pipe -mvectorize-with-neon-quad

X86ATOM_OPTION := -march=atom -mfpmath=sse -ffast-math -msse3

include $(CLEAR_VARS)
include $(call all-makefiles-under,$(LOCAL_PATH))