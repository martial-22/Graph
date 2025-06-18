cmake_minimum_required(VERSION 3.10)

project(Graph)

file(GLOB SOURCE_LIB "*.cpp" "*.h")

add_library(Graph STATIC ${SOURCE_LIB})