cmake_minimum_required(VERSION 3.12)
project(USA_Computing_Olympiad)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(USA_Computing_Olympiad src/gold/usaco2015/P3_LightsOut.cpp)
