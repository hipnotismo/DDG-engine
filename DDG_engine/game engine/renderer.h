#ifndef RENDERER_H
#define RENDERER_H
#include "export.h"

#include "glew.h"
#include "glfw3.h"

#include "Global.h"

class ENGINE_API Renderer {

public:
	Renderer();
	~Renderer();
	void DrawTriangle(Vec2 pos1, Vec2 pos2, Vec2 pos3);
	void finishRenderCycle();
	int i;
	GLuint buffer[100];

};

#endif // !RENDERER_H