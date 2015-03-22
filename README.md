lua-nanovg - NanoVG support for Lua language
============================================

lua-nanovg is a Lua binding for
[NanoVG](https://github.com/memononen/nanovg). add a light-weight
support for vector graphics support to Lua language.

lua-nanovg has a HTML5 canvas similar inteface, makes Lua client-side
GUI more easily.

lua-nanovg has the same [Licence](https://github.com/memononen/nanovg)
with Lua language.

Usage
-----

To use lua-nanovg, you should first require it, after that, you will
get a function to create context for drawing:

```lua
local ctx = require 'nvg' ()
```

You can pass some arguments to this function, to specify the atlas
size and/or edge AA (anti-alias) flags:

```lua
local ctx = require 'nvg' (256, 256, "AA") -- default
local ctx = require 'nvg' (256, 256) -- no edge anti-alias
local ctx = require 'nvg' "AA" -- use edge anti-alias, and default atlas size.
```

After you get context, you can draw with it. All APIs will exactly
same with HTML5 canvas.

API
---

sub module:
  - color
  - image
  - gradient
  - font


```lua
ctx:beginFrame()
ctx:endFrame()
ctx:color("name")
ctx:color("#rgb")
ctx:color("#argb")
ctx:color("#rrggbb")
ctx:color("#aarrggbb")
ctx:color(r,g,b)
ctx:color(r,g,b,a)
ctx:color("HSL", h,s,l);
ctx:color("HSL", h,s,l,a);

ctx:save()
ctx:restore()
ctx:reset()

ctx.strokeStyle = color|paint;
ctx.fillStyle = color|paint;

ctx.lineCap = "butt|round|square";
ctx.lineJoin = "round|bevel|miter";
ctx.lineWidth = width;
ctx.miterLimit = number;

ctx:resetTransform()
ctx:scale()
ctx:rotate()
ctx:translate()
ctx:transform()
ctx:setTransform()


ctx:image() -> ctx.image.load
ctx:drawImage()
ctx.image.new()
ctx.image.load()
=image.width
=image.height
image:update()
image:delete()

ctx:gradient()
ctx.gradient.linear()
ctx.gradient.box()
ctx.gradient.radial()

ctx:scissor()

ctx.pathWnding = "(solid|hole)|(CCW|CW)";
ctx:beginPath()
ctx:moveTo()
ctx:lineTo()
ctx:bezierTo() == ctx:bezierCurveTo()
ctx:arcTo()
ctx:closePath()

ctx:arc()
ctx:rect()
ctx:roundRect()
ctx:ellipse()
ctx:circle()
ctx:fill()
ctx:stroke()

ctx.font = font;
ctx.textAlign = 
ctx.fontBlur = number;
ctx:text()
ctx:measureText()
```
