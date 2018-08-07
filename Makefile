LUAVER?=5.3
L_EXT?=so
UNAME=$(shell uname)
SYS=$(if $(filter Linux%,$(UNAME)),linux,\
	    $(if $(filter MINGW%,$(UNAME)),mingw,\
	    $(if $(filter Darwin%,$(UNAME)),macosx,\
	        undefined\
)))

ifdef MINGW_PREFIX
	MINGW=1
	L_EXT=dll
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		LINUX=1
	endif
	ifeq ($(UNAME_S),Darwin)
		OSX=1
	endif
endif

# Linux
ifdef LINUX
PREFIX?=/usr/local
INCDIR=`pkg-config --cflags lua5.3`
endif

# OSX - Homebrew
ifdef OSX
PREFIX?=/usr/local
INCDIR=`pkg-config --cflags lua5.3`
endif

# Windows - Mingw/Msys
ifdef MINGW
PREFIX?=$(MINGW_PREFIX)
INCDIR=`pkg-config --cflags lua5.3`
endif

# Directory where to install Lua modules
L_DIR=$(PREFIX)/share/lua/$(LUAVER)
# Directory where to install Lua C modules
C_DIR=$(PREFIX)/lib/lua/$(LUAVER)
# Directory where to install C headers
H_DIR=$(PREFIX)/include
# Directory where to install C libraries
S_DIR=$(PREFIX)/lib

default : all

.PHONY: moonglfw test

all: clean moonglfw $(SYS) doc

undefined :
	@echo "I can't guess your platform, please do 'make PLATFORM' where PLATFORM is one of these:"
	@echo "      linux mingw macosx"

clean :
	@rm -fr *.$(L_EXT)
	@rm -fr *.a
	@rm -fr *.o
	@echo "Cleaned build files"
	@cd moonglfw && $(MAKE) clean

moonglfw :
	@echo "Building moonglfw dependency in $(PREFIX)"
	@cd moonglfw && INCDIR=`pkg-config --cflags lua5.3` $(MAKE) clean && cd .
	@cd moonglfw && INCDIR=`pkg-config --cflags lua5.3` $(MAKE) && cd .
	@cp moonglfw/src/moonglfw.$(L_EXT) moonglfw.$(L_EXT)

install :
	@echo "Installing moonglfw dependency in $(PREFIX)"
	@cd moonglfw && PREFIX=$(PREFIX) $(MAKE) -f Makefile install && cd .
	@echo "Installing nvg dependency in $(C_DIR)"
	@cp -f nvg.$(L_EXT) $(C_DIR)

test :
	# Test
	lua$(LUAVER) examples/test.lua

mingw : OS := MINGW
mingw : CFLAGS += -DLUAVER=$(LUAVER) -D_GLFW_USE_OPENGL -D_GLFW_WIN32 -D_GLFW_WGL -D_GLFW_BUILD_ALL -Iglfw/include $(shell pkg-config --cflags lua$(LUAVER)) -fPIC
mingw : LDFLAGS += $(shell pkg-config --libs lua$(LUAVER)) -lm -lopengl32 -lgdi32
mingw :
	# NanoVG
	gcc -c -O3 $(CFLAGS) nanovg/src/nanovg.c
	ar rcs libnanovg.a *.o
	gcc -shared -O3 $(CFLAGS) -o nvg.$(L_EXT) lua-nanovg.c libnanovg.a $(LDFLAGS)

linux : OS := LINUX
linux : CFLAGS += -DLUAVER=$(LUAVER) -D_GLFW_USE_OPENGL -D_GLFW_X11 -D_GLFW_BUILD_ALL -Iglfw/include $(shell pkg-config --cflags lua$(LUAVER)) -fPIC
linux : LDFLAGS += $(shell pkg-config --libs lua$(LUAVER))
linux :
	# NanoVG
	gcc -c -O3 $(CFLAGS) nanovg/src/nanovg.c
	ar rcs libnanovg.a *.o
	gcc -shared -O3 $(CFLAGS) -o nvg.$(L_EXT) lua-nanovg.c libnanovg.a $(LDFLAGS)

macosx : OS := MACOSX
macosx : CFLAGS += -DLUAVER=$(LUAVER) -D_GLFW_USE_OPENGL -D_GLFW_COCOA -D_GLFW_BUILD_ALL -D_GLFW_NSGL -Iglfw/include
macosx :
	# NanoVG
	gcc -c -O3 nanovg/src/nanovg.c
	ar rcs libnanovg.a *.o
	gcc  -O3 -bundle -undefined dynamic_lookup -o nvg.$(L_EXT) lua-nanovg.c libnanovg.a
