#include "Shader.h"

Shader::Shader(std::string src)
{
	Renderer::GetInstance();
	SetSrc(src);
}

void Shader::SetSrc(std::string src)
{
	if (_vertexShader == 0)
	{
		_vertexShader = glCreateShader(GL_VERTEX_SHADER);
		LoadShaderSrc(_vertexShader, VERTEX_SHADER);
		glCompileShader(_vertexShader);
	}

	glDeleteProgram(_shaderProgram);
	_shaderProgram = glCreateProgram();

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	LoadShaderSrc(fragmentShader, src);
	glCompileShader(fragmentShader);

	glAttachShader(_shaderProgram, _vertexShader);
	glAttachShader(_shaderProgram, fragmentShader);
	glLinkProgram(_shaderProgram);

	glDeleteShader(fragmentShader);

	_loadedSrc = src;
}

std::string Shader::GetSrc()
{
	return _loadedSrc;
}

void Shader::UseProgram()
{
	glUseProgram(_shaderProgram);
}

void Shader::UniformBool(std::string location, bool value)
{
	UseProgram();
	GLuint loc = GetUniformLocation(location);
	glUniform1i(loc, value);
}

void Shader::Uniform1f(std::string location, float value)
{
	UseProgram();
	GLuint loc = GetUniformLocation(location);
	glUniform1f(loc, value);
}

void Shader::Uniform2f(std::string location, glm::vec2 value)
{
	UseProgram();
	GLuint loc = GetUniformLocation(location);
	glUniform2fv(loc, 1, &value[0]);
}

void Shader::Uniform3f(std::string location, glm::vec3 value)
{
	UseProgram();
	GLuint loc = GetUniformLocation(location);
	glUniform3fv(loc, 1, &value[0]);
}

void Shader::Uniform4f(std::string location, glm::vec4 value)
{
	UseProgram();
	GLuint loc = GetUniformLocation(location);
	glUniform4fv(loc, 1, &value[0]);
}

void Shader::Uniform3x3f(std::string location, glm::mat3 value)
{
	UseProgram();
	GLuint loc = GetUniformLocation(location);
	glUniformMatrix3fv(loc, 1, GL_FALSE, &value[0][0]);
}

void Shader::Uniform4x4f(std::string location, glm::mat4 value)
{
	UseProgram();
	GLuint loc = GetUniformLocation(location);
	glUniformMatrix4fv(loc, 1, GL_FALSE, &value[0][0]);
}

void Shader::ClearUniforms()
{
	glLinkProgram(_shaderProgram);
}

void Shader::LoadShaderSrc(GLuint id, const std::string& src)
{
	const char* shader = src.c_str();
	glShaderSource(id, 1, &shader, nullptr);
}

GLuint Shader::GetUniformLocation(std::string location)
{
	return glGetUniformLocation(_shaderProgram, location.c_str());
}
