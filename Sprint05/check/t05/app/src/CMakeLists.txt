cmake_minimum_required(VERSION 3.1)

project(src LANGUAGES CXX)
add_library(src Creature.cpp Human.cpp Werewolf.cpp Wolf.cpp)
