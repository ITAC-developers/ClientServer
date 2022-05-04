cmake_minimum_required(VERSION 3.16)
project(ITAC-Common)

set(COMMON_DIR ${CMAKE_SOURCE_DIR}/ITAC/Common)

add_compile_options(-O0 -g -Werror -Wextra -Wall -pedantic)

include_directories(${COMMON_DIR}/inc)

add_library(common_lib
        src/string_funcs.cpp inc/string_funcs.h
        src/Logger.cpp inc/Logger.h
        inc/own_literals.h)

add_subdirectory(tests)

