## lua-nanovg: Lua bindings for NanoVG and NanoSVG

[![Build Status](https://travis-ci.org/iongion/lua-nanovg.svg?branch=master)](https://travis-ci.org/iongion/lua-nanovg)

lua-nanovg is a Lua binding library for [NanoVG](https://github.com/memononen/nanovg/) and [NanoSVG](https://github.com/memononen/nanosvg/).

It runs on OSX, GNU/Linux and on Windows (MSYS2/MinGW) and requires 
[Lua](http://www.lua.org/) (>=5.3)
and [GLFW](http://www.glfw.org/download.html) (>=3.1).

_Author:_ _[Xavier Wang](https://github.com/starwing)_

[![Lua logo](./doc/powered-by-lua.gif)](http://www.lua.org/)

#### License

MIT/X11 license (same as Lua). See [LICENSE](./LICENSE).

#### Documentation

See the [Reference Manual](https://starwing.github.io/lua-nanovg/doc/index.html).

#### Getting and installing

Setup the build environment as described [here](https://github.com/stetre/moonlibs), then:

```sh
$ git clone https://github.com/starwing/lua-nanovg
$ git submodule init
$ git submodule update
$ cd lua-nanovg
lua-nanovg$ make
lua-nanovg$ make install # or 'sudo make install' (Ubuntu)
```

#### Example

```lua
-- Script: hello.lua
local nvg = require "nvg"
local glfw = require("moonglfw")
-- Allocate a window and deal with OpenGL
w = glfw.create_window(640, 480, "Hello world!")
glfw.make_context_current(w)
-- Only after this we can use nanovg
local canvas = nvg.new "antialias"
-- Repeatedly poll for events:
while not glfw.window_should_close(w) do
  if glfw.get_key(w, "escape") == 'press' then break end
  t = glfw.get_time()
  ww, wh = glfw.get_window_size(w)
  mx, my = glfw.get_cursor_pos(w)
  local pw, _ = glfw.get_framebuffer_size(w)
  local ratio = pw/ww
  canvas:beginFrame(ww, wh, ratio)
  canvas:clear "#4C4C51"
  canvas:roundedRect((ww-320)/2, (wh-240)/2, 320, 240, 3)
  canvas.fillStyle = "rgba(128,30,34,100)"
  canvas:fill()
  canvas:endFrame()
  glfw.swap_buffers(w)
  glfw.poll_events()
end
```

The script can be executed at the shell prompt with the standard Lua interpreter:

```shell
$ lua hello.lua
```

Other examples can be found in the **examples/** directory contained in the release package.
