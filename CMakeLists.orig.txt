cmake_minimum_required (VERSION 3.4)
project (hello LANGUAGES CXX C)

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

# Compiler configuration
set(CMAKE_CXX_EXTENSIONS OFF)
# set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE RelWithDebInfo)
# set(CMAKE_BUILD_TYPE Release)

add_executable(hello hello.cpp)

find_package(OpenGL REQUIRED)
# set(glfw3_DIR /home/xinxin/hello/lib/cmake/glfw3)
find_package(glfw3 REQUIRED)
# find_library(GLFW3_LIBRARIES NAMES glfw3 HINTS /home/xinxin/hello/lib)

if (CMAKE_VERSION VERSION_LESS "3.0")
  # include_directories(/home/xinxin/hello/include)
  include_directories(${GLFW_INCLUDE_DIR})
  include_directories(${OPENGL_INCLUDE_DIR})
else ()
  # target_include_directories(hello PRIVATE /home/xinxin/hello/include)
  target_include_directories(hello PRIVATE ${GLFW_INCLUDE_DIR})
  target_include_directories(hello PRIVATE ${OPENGL_INCLUDE_DIR})
endif ()

target_link_libraries(hello ${OPENGL_gl_LIBRARY} -static)
target_link_libraries(hello ${GLFW3_LIBRARY} -static)
# target_link_libraries(hello ${GLFW_LIBRARIES} -static)