cmake_minimum_required(VERSION 3.15)

project(t00)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(walletManager main.cpp walletManager.cpp)
