cmake_minimum_required(VERSION 3.5)
project(Mergesort_OpenGL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Custom CMake modules, ones that are not included in CMake Find like SDL2
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

# Require AUDIERE
find_package(Audiere REQUIRED)
if (AUDIERE_FOUND)
    message(STATUS "AUDIERE_INCLUDE_DIR: ${AUDIERE_INCLUDE_DIR}")
    message(STATUS "AUDIERE_LIBRARY: ${AUDIERE_LIBRARY}")

    # Link AUDIERE library
    link_libraries(${AUDIERE_LIBRARY})
    message(STATUS "AUDIERE LIBRARY successfully linked")
endif()

# Require SDL2
find_package(SDL2 REQUIRED)
if (SDL2_FOUND)
    message(STATUS "SDL2_INCLUDE_DIR: ${SDL2_INCLUDE_DIR}")
    message(STATUS "SDL2_LIBRARY: ${SDL2_LIBRARY}")

    # Link SDL2 library
    link_libraries(${SDL2_LIBRARY})
    message(STATUS "SDL2 LIBRARY successfully linked")
endif()

# Require OpenGL
find_package(OpenGL REQUIRED)
if (OpenGL_FOUND)
    message(STATUS "OpenGL_INCLUDE_DIR: ${OPENGL_INCLUDE_DIR}")
    message(STATUS "OpenGL_LIBRARIES: ${OPENGL_LIBRARIES}")

    # Link OpenGL library
    link_libraries(${OPENGL_LIBRARIES})
    message(STATUS "OPENGL LIBRARY successfully linked")
endif()

# Require GLEW
find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    message(STATUS "GLEW_INCLUDE_DIRS: ${GLEW_INCLUDE_DIRS}")
    message(STATUS "GLEW_LIBRARIES: ${GLEW_LIBRARIES}")
    # Link GLEW library
    link_libraries(${GLEW_LIBRARIES})
    message(STATUS "GLEW LIBRARY successfully linked")
endif()

# Copy resource files to res dir
configure_file(res/sound.wav res/sound.wav COPYONLY)

set(SOURCE_FILES src/main.cpp src/mergesort.cpp src/mergesort.h src/window.cpp src/window.h src/pillar.cpp src/pillar.h src/canvas.cpp src/canvas.h src/sound.h src/sound.cpp)
add_executable(Mergesort_OpenGL ${SOURCE_FILES})
