cmake_minimum_required(VERSION 3.12)
project(Assg09_myMake C)

set(CMAKE_C_STANDARD 90)

add_executable(myMake myMake.c)
add_library(graph graph.c graph.h)