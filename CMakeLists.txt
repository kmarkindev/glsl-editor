cmake_minimum_required(VERSION 3.18)

project(glsl-editor VERSION 1.0.0 LANGUAGES CXX)

if(${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    message(FATAL "Binary dir cannot be the same as source dir")
endif()

add_executable(glsl-editor)

set_target_properties(glsl-editor
    PROPERTIES
    CXX_STANDARD_REQUIRED 20
    CXX_STANDARD 20
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

add_subdirectory(3rdparty)
add_subdirectory(src)
add_subdirectory(resources)