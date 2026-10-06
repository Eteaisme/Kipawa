cmake_minimum_required(VERSION 3.16)
project(kipawa LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(kipawa src/main.cpp)
target_link_libraries(kipawa PRIVATE tcod SDL3)
