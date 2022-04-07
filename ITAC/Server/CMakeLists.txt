cmake_minimum_required(VERSION 3.16)

project(ITACServer)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-O2 -Werror -Wextra)

add_executable(src/main.cpp)
