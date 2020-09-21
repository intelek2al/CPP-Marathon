cmake_minimum_required(VERSION 3.1)

project(src LANGUAGES CXX)
add_library(src Food.cpp Snake.cpp SnakeBlocks.cpp leaderboard.cpp Menu.cpp)
target_link_libraries (src sfml-graphics sfml-window sfml-system)
