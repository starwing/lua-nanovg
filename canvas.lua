local glfw = require "moonglfw"
local nvg = require "nvg"
local canvas = {}

function canvas.open(w, h, title)
   w = glfw.create_window(w, h, title)
   glfw.make_context_current(w)
   local ctx = nvg.new "antialias"
   local win = {}
   win.handle = w
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
   local t0 = glfw.get_time()
   local prevt = t0
   interval = interval or (1000.0/60.0)
   w = self.handle
   context = self.context
   while not glfw.window_should_close(w) do
     if glfw.get_key(self.handle, "escape") == 'press' then break end
     ww, wh = glfw.get_window_size(w)
     local pw, _ = glfw.get_framebuffer_size(w)
     local ratio = pw/ww
     -- onupdate hook
     if self.onupdate then
        local nt = glfw.get_time()
        self:onupdate(nt - t0, nt - prevt)
        prevt = nt
     end
     -- ondraw hook
     if self.ondraw then
        context:beginFrame(ww, wh, ratio)
        self.ondraw(context)
        context:endFrame()
        glfw.swap_buffers(w)
        self.shouldUpdate = false
     end
     glfw.wait_events_timeout(interval)
     glfw.poll_events()
   end
   return self
end

return canvas
