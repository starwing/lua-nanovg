package = "nanovg"
version = "0.1.3-1"
source = {
   url = "https://github.com/starwing/lua-nanovg/releases/download/0.1.3/lua-nanovg-0.1.3.zip",
   dir = "lua-nanovg-0.1.3"
}
description = {
   summary = "Lua binding for NanoVG",
   homepage = "https://github.com/starwing/lua-nanovg",
   license = "MIT"
}
dependencies = {
   "lua >= 5.1, <= 5.4"
}
build = {
   type = "builtin",
   platforms = {
      windows = {
         modules = {
            nvg = {
               libraries = {
                   "opengl32",
                   "gdi32"
               },
            }
         }
      }
   },
   modules = {
      nvg = {
         sources = {
            "lua-nanovg.c",
            "nanovg/src/nanovg.c",
         },
      },
   },
}
