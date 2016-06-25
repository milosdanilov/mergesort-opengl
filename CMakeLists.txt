cmake_minimum_required(VERSION 3.5)
project(Mergesort_OpenGL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Custom CMake modules, ones that are not included in CMake Find like SDL2
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

# Require SDL2
find_package(SDL2 REQUIRED)
if (SDL2_FOUND)
    message(STATUS "SDL2_INCLUDE_DIR: ${SDL2_INCLUDE_DIR}")
    message(STATUS "SDL2_LIBRARY: ${SDL2_LIBRARY}")

    # Link SDL2 library
    link_libraries(${SDL2_LIBRARY})
    message(STATUS "SDL2 LIBRARY successfully linked")
endif()

set(SOURCE_FILES src/main.cpp src/mergesort.cpp src/mergesort.h src/window.cpp src/window.h)
add_executable(Mergesort_OpenGL ${SOURCE_FILES})
