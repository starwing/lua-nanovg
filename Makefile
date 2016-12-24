
UNAME=$(shell uname)
SYS=$(if $(filter Linux%,$(UNAME)),linux,\
	    $(if $(filter MINGW%,$(UNAME)),mingw,\
	    $(if $(filter Darwin%,$(UNAME)),macosx,\
	        undefined\
)))

all: $(SYS)

undefined:
	@echo "I can't guess your platform, please do 'make PLATFORM' where PLATFORM is one of these:"
	@echo "      linux mingw macosx"

macosx : OS := MACOSX
macosx : CFLAGS += -D_GLFW_USE_OPENGL -D_GLFW_COCOA -D_GLFW_BUILD_ALL -D_GLFW_NSGL -Iglfw/include
macosx :
	# del old so
	rm -fr *.so
	gcc -c -O3 nanovg/src/nanovg.c
	ar rcs libnanovg.a *.o
	rm -fr *.o
	gcc  -O3 -bundle -undefined dynamic_lookup -o nvg.so lua-nanovg.c libnanovg.a
	gcc -c -O3 $(CFLAGS) glfw/src/context.c
	gcc -c -O3 $(CFLAGS) glfw/src/init.c
	gcc -c -O3 $(CFLAGS) glfw/src/input.c
	gcc -c -O3 $(CFLAGS) glfw/src/monitor.c
	gcc -c -O3 $(CFLAGS) glfw/src/vulkan.c
	gcc -c -O3 $(CFLAGS) glfw/src/window.c
	# cocoa
	gcc -c -O3 $(CFLAGS) glfw/src/cocoa_init.m
	gcc -c -O3 $(CFLAGS) glfw/src/cocoa_joystick.m
	gcc -c -O3 $(CFLAGS) glfw/src/cocoa_monitor.m
	gcc -c -O3 $(CFLAGS) glfw/src/cocoa_time.c
	gcc -c -O3 $(CFLAGS) glfw/src/cocoa_window.m
	gcc -c -O3 $(CFLAGS) glfw/src/posix_tls.c
	gcc -c -O3 $(CFLAGS) glfw/src/nsgl_context.m
	ar rcs libglfw3.a *.o
	rm -fr *.o
	gcc -O3 -bundle -undefined dynamic_lookup -o glfw.so \
	    -Iglfw/include lua-glfw.c libglfw3.a \
	    -framework OpenGL -framework CoreGraphics -framework Foundation \
	    -framework Cocoa -framework IoKit -framework CoreVideo

	lua test.lua
