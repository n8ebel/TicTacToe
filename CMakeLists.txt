cmake_minimum_required(VERSION 2.8.4)
project(TicTacToe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

include_directories(${PROJECT_SOURCE_DIR}/n8/src/Headers)
add_subdirectory(n8)

#include_directories(${n8Lib_SOURCE_DIR}/n8/Headers)

INCLUDE_DIRECTORIES(${SDL2_LIBRARY}/Headers ${SDL2_IMAGE_LIBRARY}/Headers ${SDL2_MIXER_LIBRARY}/Headers ${SDL2_TTF_LIBRARY}/Headers)

file(GLOB_RECURSE tictactoe_sources src/*.cpp)
file(GLOB_RECURSE tictactoe_headers src/*.h)

add_executable(TicTacToe ${tictactoe_sources} ${tictactoe_headers})
target_link_libraries(TicTacToe n8Lib)