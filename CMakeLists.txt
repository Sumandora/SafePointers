cmake_minimum_required(VERSION 3.20)
project(SafePointer)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_FLAGS "-ggdb3")

add_executable(SafePointer Example/Main.cpp)
target_include_directories(SafePointer PRIVATE Include)
