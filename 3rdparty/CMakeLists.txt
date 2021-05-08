# Config wxWidgets

set(wxBUILD_SHARED OFF)
set(wxBUILD_MONOLITHIC ON)
set(wxBUILD_TESTS OFF)

add_subdirectory(wxWidgets)

get_target_property(WX_INCLUDE_DIRS wxmono INCLUDE_DIRECTORIES)

target_link_libraries(glsl-editor wxmono)

target_include_directories(glsl-editor PRIVATE WX_INCLUDE_DIRS)