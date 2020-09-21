cmake_minimum_required(VERSION 3.1)

project(src LANGUAGES CXX)
add_library(src test.cpp)

include_directories(../3dparty/curlpp/include/)
include_directories(../3dparty/nanogui/include/)
include_directories(${EIGEN3_INCLUDE_DIR})
include_directories(${GLFW3_INCLUDE_DIRS})
include_directories(../3dparty/nanogui/ext/nanovg/src)

include_directories(${RACE01_EIGEN3_INCLUDE_DIR})
