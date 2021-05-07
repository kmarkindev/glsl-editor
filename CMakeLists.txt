cmake_minimum_required(VERSION 3.18)

project(glsl-editor VERSION 1.0.0 LANGUAGE CXX)

add_executable(glsl-editor)

set_property(TARGET glsl-editor PROPERTY CXX_STANDARD_REQUIRED 20)

add_subdirectory(3rdparty)
add_subdirectory(src)
add_subdirectory(resources)