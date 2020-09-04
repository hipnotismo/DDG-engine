#ifndef WINDOW_H
#define WINDOW_H

#include "export.h"
#include "glew.h"
#include "glfw3.h"

class ENGINE_API Window {

public:
	Window();
	~Window();
	int StartWindow(int width, int height, const char* windowName, GLFWwindow*& window);
};
#endif // !WINDOW_H

/*
#ifndef WINDOW_H
#define WINDOW_H

#include "export.h"

class ENGINE_API Window {

public:
	Window();
	~Window();
	int StartWindow(int width, int height, const char* windowName);
};
#endif // !WINDOW_H
*/