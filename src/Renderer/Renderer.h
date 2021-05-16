#pragma once

#include "Shader.h"

#include <glad/glad.h>
#include <exception>

class Shader;

class Renderer
{
public:

	static Renderer* GetInstance();

	Renderer(Renderer& other) = delete;
	void operator=(const Renderer&) = delete;

	void Render(Shader* shader);
	void SetViewport(int x, int y, int w, int h);

private:
	GLuint _vao;
	GLuint _vbo;
	static Renderer* _instance;

	Renderer();
	~Renderer();

	bool InitGlPointers();
	void CreateBuffers();
};