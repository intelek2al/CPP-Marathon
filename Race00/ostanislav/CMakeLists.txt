cmake_minimum_required(VERSION 3.1)

project(t00 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)                   # врубаем стандарт 17 года (по дефолту 98 или 03 почему-то)
set(CMAKE_CXX_EXTENSIONS OFF)                # уточняет, что компилим как -std=c++17, а не -std=gnu++17
set(CMAKE_CXX_STANDARD_REQUIRED YES)         # если не указать, то cmake будет подбирать более ранний стандарт, если 17 не доступен

add_subdirectory(3dparty)
add_subdirectory(app)
