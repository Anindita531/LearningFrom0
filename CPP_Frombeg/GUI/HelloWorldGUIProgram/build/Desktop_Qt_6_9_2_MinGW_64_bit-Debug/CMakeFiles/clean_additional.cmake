# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\HelloWorldGUIProgram_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\HelloWorldGUIProgram_autogen.dir\\ParseCache.txt"
  "HelloWorldGUIProgram_autogen"
  )
endif()
