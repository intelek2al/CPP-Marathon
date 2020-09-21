cmake_minimum_required(VERSION 3.1)

project(src LANGUAGES CXX)
add_library(src Serializer.h Serializer.cpp SomeClass.h SomeClass.cpp)
