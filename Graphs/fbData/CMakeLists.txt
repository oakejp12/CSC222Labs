cmake_minimum_required(VERSION 3.1)
project(fbData)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(fbData ${SOURCE_FILES} undirected_graph.h)