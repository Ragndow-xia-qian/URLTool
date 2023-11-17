# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\OpenURLTool_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\OpenURLTool_autogen.dir\\ParseCache.txt"
  "OpenURLTool_autogen"
  )
endif()
