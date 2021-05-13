cmake_minimum_required(VERSION 3.18)

project(glsl-editor VERSION 1.0.0 LANGUAGES CXX)

if(${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    message(FATAL "Binary dir cannot be the same as source dir")
endif()

if(MSVC)
    add_executable(glsl-editor WIN32)
else()
    add_executable(glsl-editor)
endif()

set_target_properties(glsl-editor
    PROPERTIES
    CXX_STANDARD_REQUIRED 20
    CXX_STANDARD 20
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake"
)

# check if OpenGl is avaliable
find_package(OpenGL REQUIRED)

add_subdirectory(3rdparty)
add_subdirectory(src)

# copy resources to the build folder
add_custom_command(TARGET glsl-editor PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/resources/ $<TARGET_FILE_DIR:glsl-editor>/resources)