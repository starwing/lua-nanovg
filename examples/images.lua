-- Script: hello.lua
local glfw = require "moonglfw"
local nvg = require "nvg"
local color = require "nvg.color"
local pprint = require "pprint"

-- Allocate a window and deal with OpenGL
w = glfw.create_window(640, 480, "Hello world!")
glfw.make_context_current(w)
-- Only after this we can use nanovg
local ctx = nvg.new "antialias"
-- Load raster assets
raster = ctx:image("nanovg/example/images/image1.jpg")
local dx = (640 - raster.width)/2
local dy = (480 - raster.height)/2
raster:extent(dx, dy , raster.width, raster.height)
-- Load svg assets
vector = ctx:image("nanosvg/example/nano.svg")
local vdx = (640 - vector.width)/2
local vdy = (480 - vector.height)/2
vector:extent(vdx, vdy , vector.width, vector.height)
-- Repeatedly poll for events:
while not glfw.window_should_close(w) do
  if glfw.get_key(w, "escape") == 'press' then break end
  t = glfw.get_time()
  ww, wh = glfw.get_window_size(w)
  mx, my = glfw.get_cursor_pos(w)
  local pw, _ = glfw.get_framebuffer_size(w)
  local ratio = pw/ww
  ctx:beginFrame(ww, wh, ratio)
  ctx:clear "#4C4C51"
  -- Raster
  ctx:beginPath()
  ctx:rect(dx,dy , raster.width, raster.height)
  ctx.fillStyle = raster
  ctx:fill()
  -- Vector
  ctx:beginPath()
  ctx:rect(vdx,vdy , vector.width, vector.height)
  ctx.fillStyle = vector
  ctx:fill()
  -- Flush
  ctx:endFrame()
  glfw.swap_buffers(w)
  glfw.poll_events()
end
