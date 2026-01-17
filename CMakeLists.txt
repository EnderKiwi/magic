cmake_minimum_required(VERSION 3.28)
project(magic C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(src)

include_directories(./src/)
add_executable(magictest main.c)
target_link_libraries(magictest magic)