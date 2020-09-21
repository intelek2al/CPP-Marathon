cmake_minimum_required(VERSION 3.1)
project(race01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_EXE main.cpp)

add_subdirectory(src)

include_directories(../3dparty/curlpp/include/)
include_directories(../3dparty/nanogui/include/)
include_directories(${EIGEN3_INCLUDE_DIR})
include_directories(${GLFW3_INCLUDE_DIRS})
include_directories(../3dparty/nanogui/ext/nanovg/src)
add_compile_options(
        -std=c++17
        # -Werror
        -Wall
        # -Wextra
        -Wpedantic
        -Wno-unused-parameter
)

add_executable(race01 ${SOURCE_EXE})
target_link_libraries(race01 curlpp nanogui ${NANOGUI_EXTRA_LIBS})
include_directories(race01)
