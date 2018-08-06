local glfw = require "moonglfw"
local nvg = require "nvg"
local color = require "nvg.color"
local pprint = require "pprint"


local icons = {
   search        = "\xF0\x9F\x94\x8D",
   circled_cross = "\xE2\x9C\x96",
   chevron_right = "\xEE\x9D\x9E",
   check         = "\xE2\x9C\x93",
   login         = "\xEE\x9D\x80",
   trash         = "\xEE\x9C\xA9",
}

local function loadData(ctx)
   ctx:font("sans-bold",  "nanovg/example/Roboto-Bold.ttf")
   ctx:font("sans",       "nanovg/example/Roboto-Regular.ttf")
   ctx:font("icons",      "nanovg/example/entypo.ttf")
   im = ctx:image("nanovg/example/images/image1.jpg")
   svg = ctx:image("nanosvg/example/nano.svg")
   print("Loaded JPG image width: "..im.width..", height: "..im.height)
   print("Loaded SVG image width: "..svg.width..", height: "..svg.height)
   return {
     context = ctx,
     im = im,
     svg = svg,
   }
end

local function drawWindow(ctx, title, x, y, w, h)
   local cornerRadius = 3.0
   ctx:save()

   ctx:beginPath()
   ctx:roundedRect(x, y, w, h, cornerRadius)
   ctx.fillStyle = "rgba(28,30,34,192)"
   ctx:fill()


   -- drop shadow
   ctx:beginPath()
   ctx:rect(x-10, y-10, w+20, h+30)
   ctx:roundedRect(x, y, w, h, cornerRadius)
   ctx.pathWinding = "hole";
   ctx.fillStyle = ctx:boxGradient(x, y+2, w, h,
      cornerRadius, 10, "#80000000", "transparent")
   ctx:fill()

   -- header
   ctx:beginPath()
   ctx:roundedRect(x+1, y+1, w-2, 30, cornerRadius-1);
   ctx.fillStyle = ctx:linearGradient(x, y, x, y+15,
      "#08FFFFFF", "#10000000")
   ctx:fill()

   ctx:beginPath()
   ctx:moveTo(x+0.5,     y+0.5+30)
   ctx:lineTo(x+0.5+w-1, y+0.5+30)
   ctx.strokeStyle = "#20000000"
   ctx:stroke()

   ctx.fontSize = 18
   ctx.fontFace = "sans-bold"
   ctx.textAlign = "center|middle"
   ctx.fontBlur = 2
   ctx.fillStyle = "#80000000"
   ctx:text(x+w/2, y+16+1, title)

   ctx.fontBlur = 0
   ctx.fillStyle = "#A0DCDCDC"
   ctx:text(x+w/2, y+16,  title)

   ctx:restore()
end

local function drawSearchBox(ctx, text, x, y, w, h)
   local cornerRadius = h/2-1
   -- edit
   ctx:beginPath()
   ctx:roundedRect(x, y, w, h, cornerRadius)
   ctx.fillStyle = ctx:boxGradient(x, y+1.5, w, h, h/2, 5, "#20000000", "#5c000000")
   ctx:fill()

   ctx.fontSize = h*1.3
   ctx.fontFace = "icons"
   ctx.fillStyle = "#40FFFFFF"
   ctx.textAlign = "center|middle"
   ctx:text(x+h*0.55, y+h*0.55, icons.search)

   ctx.fontSize = 20
   ctx.fontFace = "sans"
   ctx.fillStyle = "#20FFFFFF"
   ctx.textAlign = "left|middle"
   ctx:text(x+h*1.05, y+h*0.5, text)

   ctx.fontSize = h*1.3
   ctx.fontFace = "icons"
   ctx.fillStyle = "#20FFFFFF"
   ctx.textAlign = "center|middle"
   ctx:text(x+w-h*0.55, y+h*0.55, icons.circled_cross)
end

local function drawDropDown(ctx, text, x, y, w, h)
   local cornerRadius = 4.0

   ctx:beginPath()
   ctx:roundedRect(x+1, y+1, w-2, h-2, cornerRadius-1)
   ctx.fillStyle = ctx:linearGradient(x, y, x, y+h, "#10FFFFFF", "#10000000")
   ctx:fill()

   ctx:beginPath()
   ctx:roundedRect(x+0.5, y+0.5, w-1, h-1, cornerRadius-0.5)
   ctx.strokeStyle = "#30000000"
   ctx:stroke()

   ctx.fontSize = 20
   ctx.fontFace = "sans"
   ctx.fillStyle = "#A0FFFFFF"
   ctx.textAlign = "left|middle"
   ctx:text(x+h*0.3, y+h*0.5, text)

   ctx.fontSize = h*1.3
   ctx.fontFace = "icons"
   ctx.fillStyle = "#40FFFFFF"
   ctx.textAlign = "center|middle"
   ctx:text(x+w-h*0.55, y+h*0.55, icons.chevron_right)
end

local function drawLabel(ctx, text, x, y, _, h)
   ctx.fontSize = 18
   ctx.fontFace = "sans"
   ctx.fillStyle = "#80FFFFFF"
   ctx.textAlign = "left|middle"
   ctx:text(x,y+h/2, text)
end

local function drawEditBoxBase(ctx, x, y, w, h)
   ctx:beginPath()
   ctx:roundedRect(x+1,y+1, w-2,h-2, 4-1)
   ctx.fillStyle = ctx:boxGradient(x+1,y+1+1.5, w-2,h-2, 3,4, "#20FFFFFF", "#20202020")
   ctx:fill()

   ctx:beginPath()
   ctx:roundedRect(x+0.5, y+0.5, w-1, h-1, 4-0.5)
   ctx.strokeStyle = "#30000000"
   ctx:stroke()
end

local function drawEditBox(ctx, text, x, y, w, h)
   drawEditBoxBase(ctx, x, y, w, h)

   ctx.fontSize = 20
   ctx.fontFace = "sans"
   ctx.fillStyle = "#40FFFFFF"
   ctx.textAlign = "left|middle"
   ctx:text(x+h*0.3, y+h*0.5, text)
end

local function drawEditBoxNum(ctx, text, units, x, y, w, h)
   drawEditBoxBase(ctx, x,y, w,h);

   local uw = ctx:textBounds(units)

   ctx.fontSize = 18
   ctx.fontFace = "sans"
   ctx.fillStyle = "rgba(255,255,255,64)"
   ctx.textAlign = "right|middle"
   ctx:text(x+w-h*0.3,y+h*0.5,units)

   ctx.fontSize = 20
   ctx.fontFace = "sans"
   ctx.fillStyle = "rgba(255,255,255,128)"
   ctx.textAlign = "right|middle"
   ctx:text(x+w-uw-h*0.5,y+h*0.5,text)
end

local function drawCheckBox(ctx, text, x, y, _, h)
   ctx.fontSize = 18
   ctx.fontFace = "sans"
   ctx.fillStyle = "rgba(255,255,255,160)"

   ctx.textAlign = "left|middle"
   ctx:text(x+28,y+h*0.5,text)

   ctx:beginPath(ctx)
   ctx:roundedRect(x+1,y+h*0.5-9, 18,18, 3)
   ctx.fillStyle = ctx:boxGradient(x+1,y+h*0.5-9+1, 18,18, 3,3, "rgba(0,0,0,32)", "rgba(0,0,0,92)");
   ctx:fill()

   ctx.fontSize = 40
   ctx.fontFace = "icons"
   ctx.fillStyle = "rgba(255,255,255,128)"
   ctx.textAlign = "center|middle"
   ctx:text(x+9+2, y+h*0.5, icons.check)
end

local function drawButton(ctx, preicon, text, x, y, w, h, col)
   local cornerRadius = 4
   local iw = 0
   col = color.parse(col)

   ctx:beginPath(ctx)
   ctx:roundedRect(x+1,y+1, w-2,h-2, cornerRadius-1)
   if col ~= 0 then
      ctx.fillStyle = col
      ctx:fill()
   end
   ctx.fillStyle = ctx:linearGradient(x,y,x,y+h,
      col == 0 and "#10FFFFFF" or "#20FFFFFF",
      col == 0 and "#10000000" or "#20000000")
   ctx:fill()

   ctx:beginPath()
   ctx:roundedRect(x+0.5,y+0.5, w-1,h-1, cornerRadius-0.5)
   ctx.strokeStyle = "rgba(0,0,0,48)"
   ctx:stroke()

   ctx.fontSize = 20
   ctx.fontFace = "sans-bold"
   local tw = ctx:textBounds(text)
   if preicon then
      ctx.fontSize = h*1.3
      ctx.fontFace = "icons"
      iw = ctx:textBounds(preicon)
      iw = iw + h*0.15
   end

   if preicon then
      ctx.fontSize = h*1.3
      ctx.fontFace = "icons"
      ctx.fillColor = "rgba(255,255,255,96)"
      ctx.textAlign = "left|middle"
      ctx:text(x+w*0.5-tw*0.5-iw*0.75, y+h*0.5, preicon)
   end

   ctx.fontSize = 20
   ctx.fontFace = "sans-bold"
   ctx.textAlign = "left|middle"
   ctx.fillStyle = "rgba(0,0,0,160)"
   ctx:text(x+w*0.5-tw*0.5+iw*0.25,y+h*0.5-1, text)
   ctx.fillStyle = "rgba(255,255,255,160)"
   ctx:text(x+w*0.5-tw*0.5+iw*0.25,y+h*0.5,text)
end

local function drawSlider(ctx, pos, x, y, w, h)
   local cy = y+h*0.5
   local kr = h*0.25

   ctx:save()

   -- Slot
   ctx:beginPath()
   ctx:roundedRect(x,cy-2, w,4, 2);
   ctx.fillStyle = ctx:boxGradient(x,cy-2+1, w,4, 2,2, "rgba(0,0,0,32)", "rgba(0,0,0,128)")
   ctx:fill()

   -- Knob Shadow
   ctx:beginPath(ctx);
   ctx:rect(x+pos*w-kr-5,cy-kr-5,kr*2+5+5,kr*2+5+5+3);
   ctx:circle(x+pos*w,cy, kr);
   ctx.pathWinding = "hole"
   ctx.fillStyle = ctx:radialGradient(x+pos*w,cy+1, kr-3,kr+3, "rgba(0,0,0,64)", "rgba(0,0,0,0)")
   ctx:fill()

   -- Knob
   ctx:beginPath()
   ctx:circle(x+pos*w,cy, kr-1)
   ctx.fillStyle = "rgba(40,43,48,255)"
   ctx:fill()
   ctx.fillStyle = ctx:linearGradient(x,cy-kr,x,cy+kr, "rgba(255,255,255,16)", "rgba(0,0,0,16)")
   ctx:fill()

   ctx:beginPath()
   ctx:circle(x+pos*w,cy, kr-0.5);
   ctx.strokeStyle = "rgba(0,0,0,92)"
   ctx:stroke()

   ctx:restore()
end

local function drawEyes(ctx, x, y, w, h, mx, my, t)
   local ex = w *0.23
   local ey = h * 0.5
   local lx = x + ex
   local ly = y + ey
   local rx = x + w - ex
   local ry = y + ey
   local br = math.min(ex, ey) * 0.5
   local blink = 1 - (math.sin(t*0.5)^200)*0.8

   ctx:beginPath()
   ctx:ellipse(lx+3.0,ly+16.0, ex,ey)
   ctx:ellipse(rx+3.0,ry+16.0, ex,ey)
   ctx.fillStyle = ctx:linearGradient(x,y+h*0.5,x+w*0.1,y+h,
      "rgba(0,0,0,32)", "rgba(0,0,0,16)")
   ctx:fill()

   ctx:beginPath()
   ctx:ellipse(lx,ly, ex,ey);
   ctx:ellipse(rx,ry, ex,ey);
   ctx.fillStyle = ctx:linearGradient(x,y+h*0.25,x+w*0.1,y+h,
      "rgba(220,220,220,255)", "rgba(128,128,128,255)")
   ctx:fill()

   do
      local dx = (mx - rx) / (ex * 10)
      local dy = (my - ry) / (ey * 10)
      local d = math.sqrt(dx*dx+dy*dy)
      if d > 1 then
         dx, dy = dx / d, dy / d
      end
      dx = dx * ex*0.4
      dy = dy * ey*0.5
      ctx:beginPath()
      ctx:ellipse(lx+dx,ly+dy+ey*0.25*(1-blink), br,br*blink)
      ctx.fillStyle = "rgba(32,32,32,255)"
      ctx:fill()
   end

   do
      local dx = (mx - rx) / (ex * 10)
      local dy = (my - ry) / (ey * 10)
      local d = math.sqrt(dx*dx+dy*dy)
      if d > 1 then
         dx, dy = dx / d, dy / d
      end
      dx = dx * ex*0.4
      dy = dy * ey*0.5
      ctx:beginPath()
      ctx:ellipse(rx+dx,ry+dy+ey*0.25*(1-blink), br,br*blink)
      ctx.fillStyle = "rgba(32,32,32,255)"
      ctx:fill()
   end

   ctx:beginPath()
   ctx:ellipse(lx,ly, ex,ey)
   ctx.fillStyle = ctx:radialGradient(lx-ex*0.25,ly-ey*0.5, ex*0.1,ex*0.75,
      "rgba(255,255,255,128)", "rgba(255,255,255,0)")
   ctx:fill()

   ctx:beginPath()
   ctx:ellipse(rx,ry, ex,ey)
   ctx.fillStyle = ctx:radialGradient(rx-ex*0.25,ry-ey*0.5, ex*0.1,ex*0.75,
      "rgba(255,255,255,128)", "rgba(255,255,255,0)")
   ctx:fill()
end

local sx, sy, samples = {}, {}, {}
local function drawGraph(ctx, x, y, w, h, t)
   local dx = w/5.0

   samples[1] = (1+math.sin(t*1.2345 +math.cos(t*0.33457)*0.44))*0.5
   samples[2] = (1+math.sin(t*0.68363+math.cos(t*1.3)*1.55))*0.5
   samples[3] = (1+math.sin(t*1.1642 +math.cos(t*0.33457)*1.24))*0.5
   samples[4] = (1+math.sin(t*0.56345+math.cos(t*1.63)*0.14))*0.5
   samples[5] = (1+math.sin(t*1.6245 +math.cos(t*0.254)*0.3))*0.5
   samples[6] = (1+math.sin(t*0.345  +math.cos(t*0.03)*0.6))*0.5

   for i = 1, 6 do
      sx[i] = x+(i-1)*dx
      sy[i] = y+h*samples[i]*0.8
   end

   -- Graph background
   ctx:beginPath()
   ctx:moveTo(sx[1], sy[1])
   for i = 2, 6 do
      ctx:bezierCurveTo(sx[i-1]+dx*0.5,sy[i-1], sx[i]-dx*0.5,sy[i], sx[i],sy[i])
   end
   ctx:lineTo(x+w, y+h)
   ctx:lineTo(x, y+h)
   ctx.fillStyle = ctx:linearGradient(x,y,x,y+h,
      "rgba(0,160,192,0)", "rgba(0,160,192,64)")
   ctx:fill()

   -- Graph line
   ctx:beginPath()
   ctx:moveTo(sx[1], sy[1]+2)
   for i = 2, 6 do
      ctx:bezierCurveTo(sx[i-1]+dx*0.5,sy[i-1]+2, sx[i]-dx*0.5,sy[i]+2, sx[i],sy[i]+2)
   end
   ctx.strokeStyle = "rgba(0,0,0,32)"
   ctx.strokeWidth = 3
   ctx:stroke()

   ctx:beginPath()
   ctx:moveTo(sx[1], sy[1])
   for i = 2, 6 do
      ctx:bezierCurveTo(sx[i-1]+dx*0.5,sy[i-1], sx[i]-dx*0.5,sy[i], sx[i],sy[i]);
   end
   ctx.strokeStyle = "rgba(0,160,192,255)"
   ctx.strokeWidth = 3
   ctx:stroke()

   -- Graph sample pos
   for i = 1, 6 do
      ctx:beginPath()
      ctx:rect(sx[i]-10, sy[i]-10+2, 20,20);
      ctx.fillStyle = ctx:radialGradient(sx[i],sy[i]+2, 3.0,8.0,
         "rgba(0,0,0,32)", "rgba(0,0,0,0)")
      ctx:fill()
   end

   ctx:beginPath()
   for i = 1, 6 do
      ctx:circle(sx[i], sy[i], 4.0)
   end
   ctx.fillStyle = "rgba(0,160,192,255)"
   ctx:fill()

   ctx:beginPath()
   for i = 1, 6 do
      ctx:circle(sx[i], sy[i], 2.0)
   end
   ctx.fillStyle = "rgba(220,220,220,255)"
   ctx:fill()

   ctx.strokeWidth = 1
end

local function drawColorWheel(ctx, x, y, w, h, t)
   local hue = math.sin(t * 0.12)
   local cx = x + w*0.5
   local cy = y + h*0.5
   local r1 = math.min(w, h) * 0.5 - 5.0
   local r0 = r1 - 20.0
   local aeps = 0.5 / r1 -- half a pixel arc length in radians (2pi cancels out).

   ctx:save()
   for i = 1, 6 do
      local a0 = (i-1) / 6.0 * math.pi * 2.0 - aeps
      local a1 =  i    / 6.0 * math.pi * 2.0 + aeps

      ctx:beginPath()
      ctx:arc(cx,cy, r0, a0,a1, "cw")
      ctx:arc(cx,cy, r1, a1,a0, "ccw")
      ctx:closePath()
      local ax = cx + math.cos(a0) * (r0+r1)*0.5
      local ay = cy + math.sin(a0) * (r0+r1)*0.5
      local bx = cx + math.cos(a1) * (r0+r1)*0.5
      local by = cy + math.sin(a1) * (r0+r1)*0.5
      ctx.fillStyle = ctx:linearGradient(ax,ay, bx,by,
         color.hsl(a0/(math.pi*2),1.0,0.55),
         color.hsl(a1/(math.pi*2),1.0,0.55))
      ctx:fill()
   end

   ctx:beginPath()
   ctx:circle(cx,cy, r0-0.5)
   ctx:circle(cx,cy, r1+0.5)
   ctx.strokeStyle = "rgba(0,0,0,64)"
   ctx.strokeWidth = 1
   ctx:stroke()

   -- Selector
   ctx:save()
   ctx:translate(cx,cy)
   ctx:rotate(hue*math.pi*2)

   -- Marker on
   ctx.strokeWidth = 2
   ctx:beginPath()
   ctx:rect(r0-1,-3,r1-r0+2,6)
   ctx.strokeStyle = "rgba(255,255,255,192)"
   ctx:stroke()

   ctx:beginPath()
   ctx:rect(r0-2-10,-4-10,r1-r0+4+20,8+20)
   ctx:rect(r0-2,-4,r1-r0+4,8)
   ctx.pathWinding = "hole"
   ctx.fillStyle = ctx:boxGradient(r0-3,-5,r1-r0+6,10, 2,4,
      "rgba(0,0,0,128)", "rgba(0,0,0,0)")
   ctx:fill()

   -- Center triangle
   local r = r0 - 6
   local ax = math.cos(120.0/180.0*math.pi) * r
   local ay = math.sin(120.0/180.0*math.pi) * r
   local bx = math.cos(-120.0/180.0*math.pi) * r
   local by = math.sin(-120.0/180.0*math.pi) * r
   ctx:beginPath()
   ctx:moveTo(r,0)
   ctx:lineTo(ax,ay)
   ctx:lineTo(bx,by)
   ctx:closePath()
   ctx.fillStyle = ctx:linearGradient(r,0, ax,ay,
      color.hsla(hue,1.0,0.5,255), "rgba(255,255,255,255)")
   ctx:fill()
   ctx.fillStyle = ctx:linearGradient((r+ax)*0.5,(0+ay)*0.5, bx,by,
      "rgba(0,0,0,0)", "rgba(0,0,0,255)")
   ctx:fill()
   ctx.strokeStyle = "rgba(0,0,0,64)"
   ctx:stroke()

   -- Select circle on triangle
   ax = math.cos(120.0/180.0*math.pi) * r*0.3
   ay = math.sin(120.0/180.0*math.pi) * r*0.4
   ctx.strokeWidth = 2
   ctx:beginPath()
   ctx:circle(ax,ay,5)
   ctx.strokeStyle = "rgba(255,255,255,192)"
   ctx:stroke()

   ctx:beginPath()
   ctx:rect(ax-20,ay-20,40,40)
   ctx:circle(ax,ay,7)
   ctx.pathWinding = "hole"
   ctx.fillStyle = ctx:radialGradient(ax,ay, 7,9, "rgba(0,0,0,64)", "rgba(0,0,0,0)")
   ctx:fill()

   ctx:restore()
end

local function drawImages(ctx, width, height)
  local dx = 144
  local dy = 44
  ctx:beginPath()
  ctx:rect(dx,dy , loaded.im.width, loaded.im.height)
  loaded.im:extent(dx,dy, loaded.im.width, loaded.im.height)
  ctx.fillStyle = loaded.im
  ctx:fill()

  ctx:beginPath()
  ctx:rect(dx*2 + 10,dy , loaded.svg.width, loaded.svg.height)
  loaded.svg:extent(dx,dy, loaded.svg.width, loaded.svg.height)
  ctx.fillStyle = loaded.svg
  ctx:fill()
  ctx:restore()
end

local function renderDemo(ctx, mx, my, width, height, t, blowup)
   local x, y

   drawEyes(ctx, width-250, 50, 150, 100, mx, my, t)
   drawGraph(ctx, 0, height/2, width, height/2, t)
   drawColorWheel(ctx, width - 300, height - 300, 250, 250, t)

   ctx:save()
   if blowup then
      ctx:rotate(math.sin(t*0.3)*5/180*math.pi)
      ctx:scale(2.0, 2.0)
   end

   -- Widgets
   drawWindow(ctx, "Widgets `n Stuff", 50, 50, 300, 400)
   x, y = 60, 95
   drawSearchBox(ctx, "Search", x, y, 280, 25)
   y = y + 40
   drawDropDown(ctx, "Effects", x,y, 280, 28)
   -- popy = y + 14
   y = y + 45

   -- Form
   drawLabel(ctx, "Login", x, y, 280, 20)
   y = y + 25
   drawEditBox(ctx, "Email", x, y, 280, 28)
   y = y + 35
   drawEditBox(ctx, "Password", x, y, 280, 28)
   y = y + 38
   drawCheckBox(ctx, "Remember me", x, y, 140, 28)
   drawButton(ctx, icons.login, "Sign in", x+138, y, 140, 28, "rgba(0,96,128,255)")
   y = y + 45

   -- slider
   drawLabel(ctx, "Diameter", x, y, 280, 20)
   y = y + 25
   drawEditBoxNum(ctx, "123.00", "px", x+180, y, 100, 28)
   drawSlider(ctx, 0.4, x, y, 170, 28)
   y = y + 55

   drawButton(ctx, icons.trash, "Delete", x, y, 160, 28, "rgba(128,16,8,255)")
   drawButton(ctx, nil, "Cancel", x+170, y, 110, 28, "rgba(0,0,0,0)");
   
   drawImages(ctx, width, height)

   ctx:restore()
end

local function renderDemoMinimal(ctx, mx, my, width, height, t, blowup)
  local x, y
  ctx:save()
  drawImages(ctx, width, height)
  ctx:restore()
end

w = glfw.create_window(640, 480, "Hello world!")
glfw.make_context_current(w)
-- Only after this we can use nanovg
local canvas = nvg.new "antialias"
loaded = loadData(canvas)

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
  renderDemo(canvas, mx, my, ww, wh, t, blowup)
  renderDemoMinimal(canvas, mx, my, ww, wh, t, blowup)
  canvas:endFrame()
  glfw.swap_buffers(w)
  glfw.poll_events()
end
