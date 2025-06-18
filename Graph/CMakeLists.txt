cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Graph)

file(GLOB SOURCE_LIB "*.cpp" "*.h")

add_library(Graph STATIC ${SOURCE_LIB})
