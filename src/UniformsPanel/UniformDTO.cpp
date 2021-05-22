#include "UniformDTO.h"

template<class T>
T UniformDTO<T>::GetValue()
{
    return _value;
}

template<class T>
void UniformDTO<T>::SetValue(T value)
{
    _value = value;
}

template<class T>
std::string UniformDTO<T>::GetName()
{
    return _name;
}

template<class T>
void UniformDTO<T>::SetName(std::string &name)
{
    _name = name;
}

template<class T>
void UniformDTO<T>::ApplyUniform(Shader *shader)
{
    shader->Uniform(GetName(), GetValue());
}

template<class T>
UniformDTO<T>::UniformDTO(std::string name, T value)
    : _name(name), _value(value)
{

}
