cmake_minimum_required(VERSION 3.5)
project(Mergesort_OpenGL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
add_executable(Mergesort_OpenGL ${SOURCE_FILES})