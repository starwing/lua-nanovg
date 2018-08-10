-- Script: hello.lua
local glfw = require("moonglfw")
local nvg = require("nvg")

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