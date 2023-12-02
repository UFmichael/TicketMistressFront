cmake_minimum_required(VERSION 3.24)
project(SFML_Test)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SFML_Test
        src/main.cpp
        src/Window.cpp
        src/Window.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/Users/micha/OneDrive/Documents/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/Users/micha/OneDrive/Documents/SFML-2.5.1/include/SFML)
target_link_libraries(SFML_Test sfml-system sfml-window sfml-graphics sfml-audio)