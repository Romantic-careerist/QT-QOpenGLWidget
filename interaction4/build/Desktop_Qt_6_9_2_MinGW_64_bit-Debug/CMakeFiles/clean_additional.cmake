# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\interaction1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\interaction1_autogen.dir\\ParseCache.txt"
  "interaction1_autogen"
  )
endif()
