# wxWidgets

set(wxBUILD_SHARED OFF)
set(wxBUILD_MONOLITHIC OFF)
set(wxBUILD_TESTS OFF)

add_subdirectory(wxWidgets)

target_link_libraries(glsl-editor wx::core wx::base wx::gl wx::stc)

# GLAD

add_subdirectory(glad)

target_link_libraries(glsl-editor glad)

# GLM

add_subdirectory(glm)

target_link_libraries(glsl-editor glm::glm)