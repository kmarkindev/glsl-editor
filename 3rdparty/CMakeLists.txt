# Config wxWidgets

set(wxBUILD_SHARED OFF)
set(wxBUILD_MONOLITHIC ON)
set(wxBUILD_TESTS OFF)

add_subdirectory(wxWidgets)

target_link_libraries(glsl-editor wx::mono)