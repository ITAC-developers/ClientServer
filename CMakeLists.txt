cmake_minimum_required(VERSION 3.16)
project(ITACServer)

set(SERVER_DIR ${CMAKE_SOURCE_DIR}/ITAC/Server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED)

set(CMAKE_CXX_FLAGS "{CMAKE_CXX_FLAGS} -O0 -g -Wall -Wextra")

add_executable(${PROJECT_NAME}	${SERVER_DIR}src/main.cpp
	${SERVEr_DIR}src/Server.cpp ${SERVER_DIR}inc/Server.h)

