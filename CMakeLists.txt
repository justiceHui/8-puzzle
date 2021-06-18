cmake_minimum_required(VERSION 3.19)
project(8-puzzle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-DLOCAL -lm")

add_executable(8-puzzle main.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include)