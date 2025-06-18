cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Graph)

set(SOURCE_EXE main.cpp)

include_directories(Graph)

add_executable(main ${SOURCE_EXE})

add_subdirectory(Graph)
target_link_libraries(main Graph)

add_subdirectory(GTests)
