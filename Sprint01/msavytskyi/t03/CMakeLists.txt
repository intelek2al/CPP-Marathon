cmake_minimum_required(VERSION 3.8)          # минимальная версия cmake для сборки проекта
project(__YOUR_PROJECT_NAME__ LANGUAGES CXX) # объявляем проект с языком (компилятором) C++

set(CMAKE_CXX_STANDARD 17)                   # врубаем стандарт 17 года (по дефолту 98 или 03 почему-то)
set(CMAKE_CXX_EXTENSIONS OFF)                # уточняет, что компилим как -std=c++17, а не -std=gnu++17
set(CMAKE_CXX_STANDARD_REQUIRED YES)         # если не указать, то cmake будет подбирать более ранний стандарт, если 17 не доступен

# добавляем флаги компиляции
# pipe просто ускоряет процесс компиляции (нет не новый флаг, это вы в танке)
add_compile_options(
    -pipe
    -Wall
    -Wextra
    -Werror
    -Wpedantic
)

set(SOURCE_EXE main.cpp)                       # тут прописываем все-все .cpp файлы
add_executable(vampireRabbits ${SOURCE_EXE}) # задает имя исполняемого файла
