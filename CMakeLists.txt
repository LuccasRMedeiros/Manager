cmake_minimum_required(VERSION 3.31.6)

project("manager" VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SRC "src/*.c*")

add_executable(${CMAKE_PROJECT_NAME} ${SRC}) 
