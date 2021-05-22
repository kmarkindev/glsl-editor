#pragma once

#include "../Renderer/Shader.h"

class IUniformDTO
{
public:
    virtual void ApplyUniform(Shader *shader) = 0;
};