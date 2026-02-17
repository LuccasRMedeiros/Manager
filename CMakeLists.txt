# This CMakeLists file should be good for a majority of projects in their
# initial development phases, requiring minor adaptations to actually build the 
# project. 
# 
# It should be a good starting point, but must be seeing as just a starting
# point. Edit as much as necessary

cmake_minimum_required(VERSION 3.31.6)

project(${PROJ_NAME} VERSION ${PROJ_VER} LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
add_compile_options(-Wall -Wextra -Werror -pedantic)

set(SRCDIR "${CMAKE_SOURCE_DIR}/src")
set(INCDIR "${CMAKE_SOURCE_DIR}/inc")
set(LIBDIR "${CMAKE_SOURCE_DIR}/lib")
file(GLOB_RECURSE SRC "${SRCDIR}/*.c")
set(LNK "")

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${SRC})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCDIR})
target_link_directories(${PROJECT_NAME} PRIVATE ${LIBDIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LNK})
