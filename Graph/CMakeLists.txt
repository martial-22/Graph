cmake_minimum_required(VERSION 3.10)

project(Graph)

set(SOURCE_LIB Graph.cpp)

add_library(Graph STATIC ${SOURCE_LIB})