cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Graph)

include_directories(Graph)

add_subdirectory(Graph)

add_subdirectory(GTests)
