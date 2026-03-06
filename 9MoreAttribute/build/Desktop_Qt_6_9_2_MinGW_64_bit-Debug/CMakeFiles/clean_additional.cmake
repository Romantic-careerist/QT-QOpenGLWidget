# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\GLSLUniform_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\GLSLUniform_autogen.dir\\ParseCache.txt"
  "GLSLUniform_autogen"
  )
endif()
