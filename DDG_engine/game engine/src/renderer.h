#ifndef RENDERER_H
#define RENDERER_H
#include "export.h"

#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "glew.h"
#include "glfw3.h"

#include "Global.h"

using namespace std;


enum ShadersType
{
	NONE = -1, VERTEX = 0, FRAGMENT = 1
};
struct ShadersSource
{
	string vertexSource;
	string fragmentSource;
};
class ENGINE_API Renderer {

public:
	Renderer();
	~Renderer();
	void DrawTriangle(CVec2 pos1, CVec2 pos2, CVec2 pos3);
	int i;
	GLuint buffer;

};

#endif // !RENDERER_H