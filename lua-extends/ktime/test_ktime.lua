local ktime = require("ktime")

local microsecond = ktime.getmicrosecond()
local millisecond = ktime.getmillisecond()

print(microsecond)
print(millisecond)
