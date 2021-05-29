target_sources(glsl-editor PRIVATE
Main.cpp
App.cpp
App.h
)

add_subdirectory(MainFrame)
add_subdirectory(RenderPanel)
add_subdirectory(Renderer)
add_subdirectory(UniformsPanel)
add_subdirectory(CodePanel)
add_subdirectory(MainToolbar)
add_subdirectory(Time)