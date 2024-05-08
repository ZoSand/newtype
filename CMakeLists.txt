cmake_minimum_required(VERSION 3.25)
project(newtype)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(core)
add_subdirectory(platform)

add_library(${PROJECT_NAME} INTERFACE)