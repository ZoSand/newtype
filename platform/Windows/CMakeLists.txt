project(ntplatform)

set(NT_PLATFORM_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(NT_PLATFORM_HDR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

if (NT_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED)
else ()
    add_library(${PROJECT_NAME} STATIC)
endif ()
add_library(newtype::platform ALIAS ${PROJECT_NAME})

target_precompile_headers(
        ${PROJECT_NAME}

        PUBLIC
        "${NT_PLATFORM_HDR_DIR}/newtype/platform/pch.hpp"
)

target_sources(
        ${PROJECT_NAME}

        PUBLIC
        "${NT_PLATFORM_HDR_DIR}/newtype/platform/library.hpp"
        "${NT_PLATFORM_HDR_DIR}/newtype/platform/pch.hpp"

        "${NT_PLATFORM_HDR_DIR}/newtype/window.hpp"

        PRIVATE
        "${NT_PLATFORM_SRC_DIR}/platform/library.cpp"
        "${NT_PLATFORM_SRC_DIR}/platform/pch.cpp"

        "${NT_PLATFORM_SRC_DIR}/window.cpp"
)

target_compile_definitions(
        ${PROJECT_NAME}

        PRIVATE
        NT_COMPILE_PLATFORM
)

target_include_directories(
        ${PROJECT_NAME}

        PUBLIC
        ${NT_PLATFORM_HDR_DIR}
)

target_link_libraries(
        ${PROJECT_NAME}

        PUBLIC
        newtype::core
)