cmake_minimum_required(VERSION 3.16)
project(ITACServer)

set(SERVER_DIR ${CMAKE_SOURCE_DIR}/ITAC/Server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED)

add_compile_options(-O0 -g -Werror -Wextra -Wall -pedantic)

include_directories(${SERVER_DIR}/inc)

add_executable(${PROJECT_NAME}	src/main.cpp
	src/Server.cpp inc/Server.h src/Socket.cpp inc/Socket.h)

add_library(Socket_lib src/Socket.cpp inc/Socket.h)

add_library(Server_lib src/Server.cpp inc/Server.h)

add_subdirectory(Tests)
