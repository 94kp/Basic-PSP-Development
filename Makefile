TARGET = Tutorial
OBJS = main.o

CFLAGS = 
CXXFLAGS =  $(CFLAGS) -std=c++14 -fno-rtti -fno-exception
ASFLAGS = $(CFLAGS)

# PSP stuff
BUILD_PRX = 1
PSP_FW_VERSION = 500
PSP_LARGE_MEMORY = 1

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Our Application
# PSP_EBOOT_ICON = ICON0.PNG

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak