# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\InputNameShowMessage_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\InputNameShowMessage_autogen.dir\\ParseCache.txt"
  "InputNameShowMessage_autogen"
  )
endif()
