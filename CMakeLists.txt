cmake_minimum_required(VERSION 3.17)
project(Enveloppe_Convexe)

set(CMAKE_CXX_STANDARD 17)

FIND_PACKAGE(SDL2 REQUIRED)
Message( STATUS "FINDING SDL2" )
Message( STATUS "SDL2_FOUND: " ${SDL2_FOUND})
IF (${SDL2_FOUND})
    Message( STATUS "SDL2_INCLUDE_DIR:" ${SDL2_INCLUDE_DIRS})
    Message( STATUS "SDL2_LIBRARY: " ${SDL2_LIBRARIES})
ELSE()
    Message( FATAL_ERROR "SDL2 NOT FOUND" )
ENDIF()

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} main.cpp Point.cpp Point.h Sommet.cpp Sommet.h Polygone.cpp Polygone.h)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})