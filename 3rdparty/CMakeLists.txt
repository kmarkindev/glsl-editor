# wxWidgets

set(wxBUILD_SHARED OFF)
set(wxBUILD_MONOLITHIC ON)
set(wxBUILD_TESTS OFF)

add_subdirectory(wxWidgets)

target_link_libraries(glsl-editor wx::mono)

# GLAD

add_subdirectory(glad)

target_link_libraries(glsl-editor glad)

# GLM

add_subdirectory(glm)

target_link_libraries(glsl-editor glm::glm)