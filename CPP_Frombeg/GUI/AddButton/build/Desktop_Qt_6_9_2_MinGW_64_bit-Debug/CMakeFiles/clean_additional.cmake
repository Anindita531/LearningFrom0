# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "AddButton_autogen"
  "CMakeFiles\\AddButton_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\AddButton_autogen.dir\\ParseCache.txt"
  )
endif()
