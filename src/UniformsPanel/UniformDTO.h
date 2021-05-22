#pragma once

#include "../Renderer/Shader.h"
#include "IUniformDTO.h"

#include <string>
#include <glm/glm.hpp>

template<class T>
class UniformDTO : public IUniformDTO
{
public:
    UniformDTO(std::string name, T value);
    T GetValue();
    void SetValue(T value);
    std::string GetName();
    void SetName(std::string &name);
    void ApplyUniform(Shader *shader) override;

private:
    std::string _name;
    T _value;
};

template class UniformDTO<bool>;
template class UniformDTO<float>;
template class UniformDTO<glm::vec2>;
template class UniformDTO<glm::vec3>;
template class UniformDTO<glm::vec4>;