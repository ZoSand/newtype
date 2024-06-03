project(ntopengl)

set(NT_OPENGL_BASE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(NT_OPENGL_BASE_HDR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

set(NT_OPENGL_COMMON_SRC_DIR "${NT_OPENGL_BASE_SRC_DIR}/Common")
set(NT_OPENGL_COMMON_HDR_DIR "${NT_OPENGL_BASE_HDR_DIR}/Common")

set(NT_OPENGL_PLATFORM_SRC_DIR "${NT_OPENGL_BASE_SRC_DIR}/${CMAKE_SYSTEM_NAME}")
set(NT_OPENGL_PLATFORM_HDR_DIR "${NT_OPENGL_BASE_HDR_DIR}/${CMAKE_SYSTEM_NAME}")

find_package(OpenGL REQUIRED)

if (NT_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED)
else ()
    add_library(${PROJECT_NAME} STATIC
            include/Common/newtype/opengl/common/pch.hpp)
endif ()
add_library(newtype::opengl ALIAS ${PROJECT_NAME})

target_precompile_headers(
        ${PROJECT_NAME}

        PUBLIC
        "${NT_OPENGL_COMMON_HDR_DIR}/newtype/opengl/common/pch.hpp"
)

target_sources(
        ${PROJECT_NAME}

        PUBLIC
        "${NT_OPENGL_COMMON_HDR_DIR}/newtype/opengl/common/pch.hpp"
        "${NT_OPENGL_COMMON_HDR_DIR}/newtype/opengl/opengl.hpp"
        "${NT_OPENGL_COMMON_HDR_DIR}/newtype/opengl/renderer.hpp"

        "${NT_OPENGL_PLATFORM_HDR_DIR}/newtype/opengl/loader.hpp"
        "${NT_OPENGL_PLATFORM_HDR_DIR}/newtype/opengl/platform/pch.hpp"
        "${NT_OPENGL_PLATFORM_HDR_DIR}/newtype/opengl/platform/library.hpp"

        PRIVATE
        "${NT_OPENGL_COMMON_SRC_DIR}/opengl/common/pch.cpp"
        "${NT_OPENGL_COMMON_SRC_DIR}/opengl/opengl.cpp"
        "${NT_OPENGL_COMMON_SRC_DIR}/opengl/renderer.cpp"

        "${NT_OPENGL_PLATFORM_SRC_DIR}/opengl/loader.cpp"
        "${NT_OPENGL_PLATFORM_SRC_DIR}/opengl/platform/pch.cpp"
        "${NT_OPENGL_PLATFORM_SRC_DIR}/opengl/platform/library.cpp"
)

target_compile_definitions(
        ${PROJECT_NAME}

        PRIVATE
        NT_COMPILE_OPENGL
)

target_include_directories(
        ${PROJECT_NAME}

        PUBLIC
        ${NT_OPENGL_COMMON_HDR_DIR}
        ${NT_OPENGL_PLATFORM_HDR_DIR}
        ${OPENGL_INCLUDE_DIR}
)

target_link_libraries(
        ${PROJECT_NAME}

        PUBLIC
        newtype::core
        ${OPENGL_LIBRARIES}
)