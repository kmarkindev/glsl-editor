#pragma once

#include <glad/glad.h>
#include <string>
#include <glm/glm.hpp>

class Shader
{
public:
	Shader(std::string src);
	void SetSrc(std::string src);
	std::string GetSrc();

	void UseProgram();

	void UniformBool(std::string location, bool value);
	void Uniform1f(std::string location, float value);
	void Uniform2f(std::string location, glm::vec2 value);
	void Uniform3f(std::string location, glm::vec3 value);
	void Uniform4f(std::string location, glm::vec4 value);
	void Uniform3x3f(std::string location, glm::mat3 value);
	void Uniform4x4f(std::string location, glm::mat4 value);

protected:
	GLuint _vertexShader = 0;
	GLuint _shaderProgram = 0;

private:
	const std::string VERTEX_SHADER =
		"#version 330 core \n"
		"layout (location = 0) in vec2 VertPos; \n"
		"void main(){ \n"
		"gl_Position = vec4(VertPos.x, VertPos.y, 0.0f, 1.0f); \n"
		"}";

	std::string _loadedSrc = "";

	void LoadShaderSrc(GLuint id, const std::string& src);
	GLuint GetUniformLocation(std::string location);
};