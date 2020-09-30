#ifndef RENDERER_H
#define RENDERER_H
#include "export.h"

#include <stdlib.h>
#include <string>
#include <iostream>
#include "glew.h"
#include "glfw3.h"

using namespace std;

#include "Global.h"

class ENGINE_API Renderer {

public:
	Renderer();
	~Renderer();
	void DrawTriangle(CVec2 pos1, CVec2 pos2, CVec2 pos3);
	int i;
	GLuint buffer;

};

#endif // !RENDERER_H