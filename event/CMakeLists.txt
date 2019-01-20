cmake_minimum_required(VERSION 2.8)
project(app)

# Compiler configuration
if (CMAKE_VERSION VERSION_LESS "3.1")
  if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++1y")
  endif ()
else ()
  # set (CMAKE_CXX_STANDARD 11)
  set (CMAKE_CXX_STANDARD 14)
endif ()

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE RelWithDebInfo)
# set(CMAKE_BUILD_TYPE Release)

find_library(LIBEVENT2 event)

add_executable(http http-server.c)
target_link_libraries(http ${LIBEVENT2})

add_executable(web40 web40.c)
target_link_libraries(web40 ${LIBEVENT2})

add_executable(http40 http40.cpp)
target_link_libraries(http40 ${LIBEVENT2})