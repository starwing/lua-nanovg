local glfw = require "glfw"
local nvg = require "nvg"
local canvas = {}

function canvas.open(w, h, title)
   local win = assert(glfw.window(w, h, title))
   win:makecurrent()
   local ctx = nvg.new "antialias"
   win.context = ctx
   win.loop   = canvas.loop
   win.update = canvas.update
   return win, ctx
end

function canvas:update()
   self.shouldUpdate = true
   return self
end

function canvas:loop(interval)
   local ctx = self.context
   interval = interval or (1000.0/60.0)

   local t0 = glfw.time()
   local prevt = t0
   self.shouldUpdate = true
   while not self:shouldclose() do
      if self:key "esc" then break end
      local ww, wh = self:size()
      local pw, _ = self:fbsize()
      local ratio = pw/ww

      if self.onupdate then
         local nt = glfw.time()
         self:onupdate(nt - t0, nt - prevt)
         prevt = nt
      end

      if self.ondraw and self.shouldUpdate then
         ctx:beginFrame(ww, wh, ratio)
         self:ondraw(ctx)
         ctx:endFrame()
         self:swapbuffers()
         self.shouldUpdate = false
      end

      glfw.wait(interval)
   end
   return self
end

return canvas

