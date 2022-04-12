cmake_minimum_required(VERSION 3.16)
project(ITAC-Server)

set(SERVER_DIR ${CMAKE_SOURCE_DIR}/ITAC/Server)

add_compile_options(-O0 -g -Werror -Wextra -Wall -pedantic)

include_directories(${SERVER_DIR}/inc)

add_executable(${PROJECT_NAME}	src/main.cpp
	src/Server.cpp inc/Server.h)

add_library(Server_lib src/Server.cpp inc/Server.h)

add_subdirectory(Tests)
