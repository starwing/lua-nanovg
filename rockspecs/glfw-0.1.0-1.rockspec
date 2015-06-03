package = "glfw"
version = "0.1.0-1"
source = {
   url = "https://github.com/starwing/lua-nanovg/archive/0.1.0.zip",
   dir = "lua-nanovg-0.1.0"
}
description = {
   summary = "Lua binding for GLFW",
   homepage = "https://github.com/starwing/lua-nanovg",
   license = "MIT"
}
dependencies = {
   "lua >= 5.1, < 5.4"
}
build = {
   type = "builtin",
   platforms = {
      windows = {
         modules = {
            glfw = {
               defines = {
                  "_GLFW_WIN32",
                  "_GLFW_USE_OPENGL",
                  "_GLFW_WGL",
                  "_GLFW_BUILD_DLL",
               },
               incdirs = {
                  "glfw/include",
               },
               libraries = {
                  "gdi32", "winmm", "opengl32"
               },
               sources = {
                  "lua-glfw.c",
                  "glfw/src/context.c",
                  "glfw/src/init.c",
                  "glfw/src/input.c",
                  "glfw/src/monitor.c",
                  "glfw/src/window.c",

                  "glfw/src/wgl_context.c",
                  "glfw/src/win32_init.c",
                  "glfw/src/win32_monitor.c",
                  "glfw/src/win32_time.c",
                  "glfw/src/win32_tls.c",
                  "glfw/src/win32_window.c",
                  "glfw/src/winmm_joystick.c",
               }
            }
         }
      }
   }
}
