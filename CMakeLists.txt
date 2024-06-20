cmake_minimum_required(VERSION 3.20)
PROJECT(chess)    

set(CXX_FLAGS
 -g
 -DVALGRIND
 -DCHECK_PTHREAD_RETURN_VALUE
 -D_FILE_OFFSET_BITS=64
 -Wall
 -Wextra
 -Werror
 -Wconversion
 -Wno-unused-parameter
#  -Wold-style-cast
 -Woverloaded-virtual
 -Wpointer-arith
#  -Wshadow
#  -Wwrite-strings
 -march=native
 # -MMD
 -std=c++14 
 -rdynamic
 )
if(CMAKE_BUILD_BITS EQUAL 32)
  list(APPEND CXX_FLAGS "-m32")
endif()
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  list(APPEND CXX_FLAGS "-Wno-null-dereference")
  list(APPEND CXX_FLAGS "-Wno-sign-conversion")
  list(APPEND CXX_FLAGS "-Wno-unused-local-typedef")
  list(APPEND CXX_FLAGS "-Wthread-safety")
  list(REMOVE_ITEM CXX_FLAGS "-rdynamic")
endif()
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

set(CMAKE_VERBOSE_MAKEFILE off)
# SET(CMAKE_C_COMPILER "/usr/bin/gcc")
# SET(CMAKE_CXX_COMPILER "/usr/bin/g++")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

find_package(GTest REQUIRED)
# get_property(pkg_vars DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VARIABLES)
# foreach(var ${pkg_vars})
#     if(var MATCHES "^GTEST_")
#         message("${var} = ${${var}}")
#     endif()
# endforeach()
if(GTEST_FOUND)
  message(STATUS "found gtest")
  include_directories(${GTEST_INCLUDE_DIRS})
  link_directories(${GGTEST_BOTH_LIBRARIES})
endif()


enable_testing()

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(chess)

message(STATUS "CXX_FLAGS = " ${CMAKE_CXX_FLAGS} " " ${CMAKE_CXX_FLAGS_${BUILD_TYPE}})

set(src
    main.cpp
)
set(tn app)
add_executable(${tn} ${src})
target_link_libraries(${tn} pthread gtest ds)
