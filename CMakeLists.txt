cmake_minimum_required(VERSION 3.15)
project(FigureProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Основная программа
add_executable(main
    main.cpp
)

# Включаем математическую библиотеку
if(UNIX AND NOT APPLE)
    target_link_libraries(main m)
endif()
