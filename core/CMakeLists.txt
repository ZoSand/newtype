project(ntcore)

set(NT_CORE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(NT_CORE_HDR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

if (NT_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED)
else ()
    add_library(${PROJECT_NAME} STATIC)
endif ()
add_library(newtype::core ALIAS ${PROJECT_NAME})

target_precompile_headers(
        ${PROJECT_NAME}

        PUBLIC
        "${NT_CORE_HDR_DIR}/newtype/core/pch.hpp"
)

target_sources(
        ${PROJECT_NAME}

        PUBLIC
        "${NT_CORE_HDR_DIR}/newtype/core/library.hpp"
        "${NT_CORE_HDR_DIR}/newtype/core/pch.hpp"

        "${NT_CORE_HDR_DIR}/newtype/window_base.hpp"

        "${NT_CORE_HDR_DIR}/newtype/application_base.hpp"

        "${NT_CORE_HDR_DIR}/newtype/core.hpp"

        PRIVATE
        "${NT_CORE_SRC_DIR}/core/library.cpp"
        "${NT_CORE_SRC_DIR}/core/pch.cpp"

        "${NT_CORE_SRC_DIR}/window_base.cpp"

        "${NT_CORE_SRC_DIR}/application_base.cpp"

        "${NT_CORE_SRC_DIR}/core.cpp"
)

string(TOUPPER ${CMAKE_SYSTEM_NAME} NT_PLATFORM_NAME)

target_compile_definitions(
        ${PROJECT_NAME}
        PUBLIC

        NT_PLATFORM_${NT_PLATFORM_NAME}

        $<$<BOOL:${NT_SHARED_LIBS}>:NT_SHARED_LIBS>
        $<$<STREQUAL:${CMAKE_BUILD_TYPE},Debug>:NT_DEBUG>
        $<$<STREQUAL:${CMAKE_BUILD_TYPE},Release>:NT_RELEASE>

        PRIVATE
        NT_COMPILE_CORE
)

target_include_directories(
        ${PROJECT_NAME}

        PUBLIC
        ${NT_CORE_HDR_DIR}
)