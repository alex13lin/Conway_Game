cmake_minimum_required(VERSION 3.22)
project(Conway_Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(Conway_Game main.cpp Cell.cpp Cell.h Life.cpp Life.h)
