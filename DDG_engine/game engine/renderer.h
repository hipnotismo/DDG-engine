#ifndef RENDERER_H
#define RENDERER_H
#include "export.h"

#include <stdlib.h>
#include <iostream>
#include "glew.h"
#include "glfw3.h"

#include "Global.h"

class ENGINE_API Renderer {

public:
	Renderer();
	~Renderer();
	void DrawTriangle(Vec2 pos1, Vec2 pos2, Vec2 pos3);
	//void DrawTriangle();
};

#endif // !RENDERER_H