# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\GLSLinOut_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\GLSLinOut_autogen.dir\\ParseCache.txt"
  "GLSLinOut_autogen"
  )
endif()
