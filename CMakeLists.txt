cmake_minimum_required(VERSION 3.10)
project(cpp_benchmarks)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_BUILD_TYPE Debug)

option(TESTS "enable/disable tests" ON)

add_compile_options(
    -Wall
    -Wextra
    -Werror
    -Wshadow
    -Wnon-virtual-dtor
    -pedantic
    )

add_subdirectory(libs)

include_directories(include)
add_subdirectory(src)
