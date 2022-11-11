CMAKE_MINIMUM_REQUIRED (VERSION 3.1)
project (socks5)

# The version number.
set (utility_VERSION_MAJOR 1)
set (utility_VERSION_MINOR 0)

# Build type
if(NOT CMAKE_BUILD_TYPE) 
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

file(GLOB_RECURSE SOCK5_SOURCES CONFIGURE_DEPENDS
  inc/*.*
  src/*.*
)

add_library(sock5 ${SOCK5_SOURCES})
include_directories(./inc)

if(${CMAKE_CXX_COMPILER_ID} EQUAL MSVC)

elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
  if (${CMAKE_CXX_COMPILER} STREQUAL "/opt/gcc-linaro-7.2.1-2017.11-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++")
    # for cross compile
    LINK_DIRECTORIES(/mnt/d/opensources/boost_1_80_0/stage/lib/)
  else()
    # for x86
  endif()
endif()

# executable 	
ADD_EXECUTABLE(sock5_main bin/main.c)
TARGET_LINK_LIBRARIES (sock5_main sock5)