cmake_minimum_required(VERSION 3.15)

project(t05)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(meadSong main.cpp meadSong.cpp meadSong.h)
