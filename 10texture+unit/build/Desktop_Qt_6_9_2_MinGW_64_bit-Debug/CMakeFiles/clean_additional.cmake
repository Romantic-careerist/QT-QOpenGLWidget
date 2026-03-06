# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\texture_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\texture_autogen.dir\\ParseCache.txt"
  "texture_autogen"
  )
endif()
