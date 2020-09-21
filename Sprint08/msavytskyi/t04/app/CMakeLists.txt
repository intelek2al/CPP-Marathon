cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)       
set(CMAKE_CXX_STANDARD_REQUIRED YES)

project(serializer LANGUAGES CXX)
set(SOURCE_EXE main.cpp)
add_subdirectory(src)

add_compile_options(
        -Werror
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-parameter
)

add_executable(serializer ${SOURCE_EXE})
target_link_libraries(serializer src)
