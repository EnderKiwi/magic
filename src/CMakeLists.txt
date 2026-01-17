cmake_minimum_required(VERSION 3.28)
project(magic C)

set(CMAKE_C_STANDARD 99)


add_library(magic print.c colors.h)
