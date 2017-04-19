cmake_minimum_required(VERSION 3.6)
project(RC4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp RC4.cpp RC4.h)
add_executable(RC4 ${SOURCE_FILES})