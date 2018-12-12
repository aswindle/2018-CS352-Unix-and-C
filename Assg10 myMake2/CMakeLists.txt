cmake_minimum_required(VERSION 3.12)
project(Assg10_myMake2 C)

set(CMAKE_C_STANDARD 90)

add_executable(myMake2 mymake2.c)
add_library(graph graph.c graph.h)