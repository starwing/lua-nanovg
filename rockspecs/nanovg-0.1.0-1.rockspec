package = "nanovg"
version = "0.1.0-1"
source = {
   url = "https://github.com/starwing/lua-nanovg/archive/0.1.0.tar.gz",
   dir = "lua-nanovg-0.1.0"
}
description = {
   summary = "Lua binding for NanoVG",
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
            nvg = {
               libraries = { "opengl32" },
            }
         }
      }
   },
   modules = {
      nvg = {
         sources = {
            "lua-nanovg.c",
            "nanovg/src/nanovg.c",
            "gl_2_0_core.c",
         },
      },
   },
}
