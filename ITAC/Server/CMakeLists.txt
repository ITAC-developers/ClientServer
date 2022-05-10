cmake_minimum_required(VERSION 3.16)
project(ITAC-Server)

set(SERVER_DIR ${CMAKE_SOURCE_DIR}/ITAC/Server)

add_compile_options(-O0 -g -Werror -Wextra -Wall -pedantic)

include_directories(${SERVER_DIR}/inc)
include_directories(${CMAKE_SOURCE_DIR}/ITAC/Common/inc)

add_executable(${PROJECT_NAME}	src/main.cpp
	src/Server.cpp inc/Server.h src/Socket.cpp inc/Socket.h)

add_library(Socket_lib src/Socket.cpp inc/Socket.h)

add_library(Server_lib src/Server.cpp inc/Server.h)

target_link_libraries(${PROJECT_NAME} common_lib)

add_subdirectory(Tests)
