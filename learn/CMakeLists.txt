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
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE RelWithDebInfo)
# set(CMAKE_BUILD_TYPE Release)


#find_package(glfw3 3.2 REQUIRED)
#find_package(OpenGL REQUIRED)

add_library(learn STATIC learn.cpp)

add_executable(app main.cpp)

set_property(TARGET app PROPERTY CXX_STANDARD 11)

target_link_libraries(app learn)

add_executable(hr_sum_array hr_sum_array.cpp)
add_executable(timer timer.cpp)

#target_include_directories(app PRIVATE ${OPENGL_INCLUDE_DIR})
#target_link_libraries(app ${OPENGL_gl_LIBRARY} -static)

#target_link_libraries(app glfw3 -static)
