cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -pedantic -Wextra")

project (rolePlayer)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(CODE_DIR ${CMAKE_SOURCE_DIR}/src)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/libs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/libs)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(${CODE_DIR})
add_subdirectory(${INCLUDE_DIR})

#add_executable(rolePlayer src/rolePlayer.cpp)
