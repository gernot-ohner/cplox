cmake_minimum_required(VERSION 3.20)
project(cplox)

set(CMAKE_CXX_STANDARD 17)

add_executable(cplox main.cpp Chunk.cpp Chunk.h Value.cpp Value.h debug.cpp debug.h)

find_package(fmt)
target_link_libraries(cplox fmt::fmt)