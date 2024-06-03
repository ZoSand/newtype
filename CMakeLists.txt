cmake_minimum_required(VERSION 3.25)
project(newtype)

if (${CMAKE_CXX_STANDARD} AND (${CMAKE_CXX_STANDARD} LESS 20))
    message(FATAL_ERROR "CXX standard must be at least C++20")
elseif (NOT EXISTS ${CMAKE_CXX_STANDARD})
    set(CMAKE_CXX_STANDARD 20)
endif ()

add_subdirectory(core)
add_subdirectory(opengl)

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
        INTERFACE newtype::opengl
)