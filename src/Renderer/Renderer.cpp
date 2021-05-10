#include "Renderer.h"

Renderer* Renderer::_instance = nullptr;

Renderer::Renderer()
{
	if (!InitGlPointers())
	{
		throw std::exception();
	}

	CreateBuffers();
}

Renderer::~Renderer()
{
	
}

Renderer* Renderer::GetInstance()
{
	if (_instance)
		return _instance;

	return _instance = new Renderer();
}

void Renderer::Render(Shader* shader)
{
	shader->UseProgram();

	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(_vao);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void Renderer::SetViewport(int x, int y, int w, int h)
{
	glViewport(x, y, w, h);
}

bool Renderer::InitGlPointers()
{
	bool isInitialized = GLVersion.major != 0;

	if (!isInitialized)
		isInitialized = gladLoadGL();

	return isInitialized;
}

void Renderer::CreateBuffers()
{
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);

	float verticles[] = {
		1,  1,
	   -1,  1,
	   -1, -1,

		1,  1,
	   -1, -1,
		1, -1
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(verticles), verticles, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
