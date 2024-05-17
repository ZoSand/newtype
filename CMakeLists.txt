cmake_minimum_required(VERSION 3.25)
project(newtype)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(core)

add_library(
        ${PROJECT_NAME}

        INTERFACE
)
add_library(
        newtype::newtype

        ALIAS
        ${PROJECT_NAME}
)

target_link_libraries(
        ${PROJECT_NAME}

        INTERFACE newtype::core
)