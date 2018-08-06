LUAVER=5.3
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

mingw : OS := MINGW
mingw : CFLAGS += -D_GLFW_USE_OPENGL -D_GLFW_WIN32 -D_GLFW_WGL -D_GLFW_BUILD_ALL -Iglfw/include $(shell pkg-config --cflags lua$(LUAVER)) -fPIC
mingw : LDFLAGS += $(shell pkg-config --libs lua$(LUAVER)) -lm -lopengl32 -lgdi32
mingw :
	rm -fr *.dll
	rm -fr *.o
	# glfw
	gcc -c -O3 $(CFLAGS) glfw/src/context.c
	gcc -c -O3 $(CFLAGS) glfw/src/init.c
	gcc -c -O3 $(CFLAGS) glfw/src/input.c
	gcc -c -O3 $(CFLAGS) glfw/src/monitor.c
	gcc -c -O3 $(CFLAGS) glfw/src/vulkan.c
	gcc -c -O3 $(CFLAGS) glfw/src/window.c
	# x11
	gcc -c -O3 $(CFLAGS) glfw/src/win32_init.c
	gcc -c -O3 $(CFLAGS) glfw/src/win32_joystick.c
	gcc -c -O3 $(CFLAGS) glfw/src/win32_monitor.c
	gcc -c -O3 $(CFLAGS) glfw/src/win32_time.c
	gcc -c -O3 $(CFLAGS) glfw/src/win32_window.c
	gcc -c -O3 $(CFLAGS) glfw/src/win32_thread.c
	gcc -c -O3 $(CFLAGS) glfw/src/wgl_context.c
	gcc -c -O3 $(CFLAGS) glfw/src/egl_context.c
	gcc -c -O3 $(CFLAGS) glfw/src/osmesa_context.c
	ar rcs libglfw3.a *.o
	gcc -shared -O3 $(CFLAGS) -o glfw.dll \
	    -Iglfw/include lua-glfw.c libglfw3.a $(LDFLAGS)
	# NanoVG
	gcc -c -O3 $(CFLAGS) nanovg/src/nanovg.c
	ar rcs libnanovg.a *.o
	gcc -shared -O3 $(CFLAGS) -o nvg.dll lua-nanovg.c libnanovg.a $(LDFLAGS)
	# Test
	lua$(LUAVER) test.lua

linux : OS := LINUX
linux : CFLAGS += -D_GLFW_USE_OPENGL -D_GLFW_X11 -D_GLFW_BUILD_ALL -Iglfw/include $(shell pkg-config --cflags lua$(LUAVER)) -fPIC
linux : LDFLAGS += $(shell pkg-config --libs lua$(LUAVER)) $(LDFLAGS)
linux :
	rm -fr *.so
	rm -fr *.o
	# glfw
	gcc -c -O3 $(CFLAGS) glfw/src/context.c
	gcc -c -O3 $(CFLAGS) glfw/src/init.c
	gcc -c -O3 $(CFLAGS) glfw/src/input.c
	gcc -c -O3 $(CFLAGS) glfw/src/monitor.c
	gcc -c -O3 $(CFLAGS) glfw/src/vulkan.c
	gcc -c -O3 $(CFLAGS) glfw/src/window.c
	# x11
	gcc -c -O3 $(CFLAGS) glfw/src/x11_init.c
	gcc -c -O3 $(CFLAGS) glfw/src/linux_joystick.c
	gcc -c -O3 $(CFLAGS) glfw/src/x11_monitor.c
	gcc -c -O3 $(CFLAGS) glfw/src/posix_time.c
	gcc -c -O3 $(CFLAGS) glfw/src/xkb_unicode.c
	gcc -c -O3 $(CFLAGS) glfw/src/x11_window.c
	gcc -c -O3 $(CFLAGS) glfw/src/posix_thread.c
	gcc -c -O3 $(CFLAGS) glfw/src/glx_context.c
	gcc -c -O3 $(CFLAGS) glfw/src/egl_context.c
	gcc -c -O3 $(CFLAGS) glfw/src/osmesa_context.c
	ar rcs libglfw3.a *.o
	gcc -shared -O3 $(CFLAGS) -o glfw.so \
	    -Iglfw/include lua-glfw.c libglfw3.a $(LDFLAGS)
	# NanoVG
	gcc -c -O3 $(CFLAGS) nanovg/src/nanovg.c
	ar rcs libnanovg.a *.o
	gcc -shared -O3 $(CFLAGS) -o nvg.so lua-nanovg.c libnanovg.a $(LDFLAGS)
	# Test
	lua$(LUAVER) test.lua

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
	gcc -c -O3 $(CFLAGS) glfw/src/posix_thread.c
	gcc -c -O3 $(CFLAGS) glfw/src/nsgl_context.m
	gcc -c -O3 $(CFLAGS) glfw/src/egl_context.c
	gcc -c -O3 $(CFLAGS) glfw/src/osmesa_context.c
	ar rcs libglfw3.a *.o
	rm -fr *.o
	gcc -O3 -bundle -undefined dynamic_lookup -o glfw.so \
	    -Iglfw/include lua-glfw.c libglfw3.a \
	    -framework OpenGL -framework CoreGraphics -framework Foundation \
	    -framework Cocoa -framework IoKit -framework CoreVideo
	lua$(LUAVER) test.lua
