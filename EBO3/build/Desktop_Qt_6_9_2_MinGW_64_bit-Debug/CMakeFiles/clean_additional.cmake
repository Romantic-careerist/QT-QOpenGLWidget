# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\EBO1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\EBO1_autogen.dir\\ParseCache.txt"
  "EBO1_autogen"
  )
endif()
