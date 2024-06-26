project(ntcore)

set(NT_CORE_BASE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(NT_CORE_BASE_HDR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

set(NT_CORE_COMMON_SRC_DIR "${NT_CORE_BASE_SRC_DIR}/Common")
set(NT_CORE_COMMON_HDR_DIR "${NT_CORE_BASE_HDR_DIR}/Common")

set(NT_CORE_PLATFORM_SRC_DIR "${NT_CORE_BASE_SRC_DIR}/${CMAKE_SYSTEM_NAME}")
set(NT_CORE_PLATFORM_HDR_DIR "${NT_CORE_BASE_HDR_DIR}/${CMAKE_SYSTEM_NAME}")

if (NT_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED)
else ()
    add_library(${PROJECT_NAME} STATIC)
endif ()
add_library(newtype::core ALIAS ${PROJECT_NAME})

target_precompile_headers(
        ${PROJECT_NAME}

        PUBLIC
        "${NT_CORE_COMMON_HDR_DIR}/newtype/core/pch.hpp"
)

target_sources(
        ${PROJECT_NAME}

        PUBLIC
        #Common
        "${NT_CORE_COMMON_HDR_DIR}/newtype/core/common/pch.hpp"

        "${NT_CORE_COMMON_HDR_DIR}/newtype/core/pch.hpp"

        "${NT_CORE_COMMON_HDR_DIR}/newtype/core/window_base.hpp"
        "${NT_CORE_COMMON_HDR_DIR}/newtype/core/renderer_base.hpp"

        "${NT_CORE_COMMON_HDR_DIR}/newtype/core/application_base.hpp"

        "${NT_CORE_COMMON_HDR_DIR}/newtype/core/core.hpp"

        #platform
        "${NT_CORE_PLATFORM_HDR_DIR}/newtype/core/platform/pch.hpp"
        "${NT_CORE_PLATFORM_HDR_DIR}/newtype/core/platform/library.hpp"

        "${NT_CORE_PLATFORM_HDR_DIR}/newtype/core/window.hpp"

        PRIVATE
        #Common
        "${NT_CORE_COMMON_SRC_DIR}/core/pch.cpp"

        "${NT_CORE_COMMON_SRC_DIR}/core/pch.cpp"

        "${NT_CORE_COMMON_SRC_DIR}/core/window_base.cpp"
        "${NT_CORE_COMMON_SRC_DIR}/core/renderer_base.cpp"

        "${NT_CORE_COMMON_SRC_DIR}/core/application_base.cpp"

        "${NT_CORE_COMMON_SRC_DIR}/core/core.cpp"

        #platform
        "${NT_CORE_PLATFORM_SRC_DIR}/core/platform/pch.cpp"
        "${NT_CORE_PLATFORM_SRC_DIR}/core/platform/library.cpp"

        "${NT_CORE_PLATFORM_SRC_DIR}/core/window.cpp"
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
        ${NT_CORE_COMMON_HDR_DIR}
        ${NT_CORE_PLATFORM_HDR_DIR}
)