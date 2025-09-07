# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/PetShop_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/PetShop_autogen.dir/ParseCache.txt"
  "PetShop_autogen"
  )
endif()
