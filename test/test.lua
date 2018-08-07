pcall(require, "luacov")


print("------------------------------------")
print("Lua version: " .. (jit and jit.version or _VERSION))
print("------------------------------------")
print("")

local HAS_RUNNER = not not lunit
local lunit = require "lunit"
local TEST_CASE = lunit.TEST_CASE

local _ENV = TEST_CASE"NVG"

function test_1()
  local moonglfw = require "moonglfw"
  local ctx = require "nvg"
  assert_function(ctx.beginPath)
end

if not HAS_RUNNER then lunit.run() end
