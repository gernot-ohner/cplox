cmake_minimum_required(VERSION 3.20)
project(cplox)

set(CMAKE_CXX_STANDARD 17)

add_executable(cplox
        src/main.cpp
        src/Chunk.cpp
        src/Chunk.h
        src/Value.cpp
        src/Value.h
        src/debug.cpp
        src/debug.h
        )

add_executable(cplox_tests
        tests/tests.cpp
        src/Chunk.cpp
        src/Chunk.h
        src/Value.cpp
        src/Value.h
        src/debug.cpp
        src/debug.h
        tests/DebugTests.cpp)

find_package(fmt)
target_link_libraries(cplox fmt::fmt)
target_link_libraries(cplox_tests fmt::fmt)
