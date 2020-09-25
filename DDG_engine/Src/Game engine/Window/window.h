
#ifndef WINDOW_H
#define WINDOW_H

#include "Game engine/Export/export.h"

#include <stdlib.h>
#include <string>
#include <iostream>
#include "glew.h"
#include "glfw3.h"

class ENGINE_API Window {

public:
	Window();
	~Window();
	GLFWwindow* window;
	int Start(int width, int height, const char* windowName);
	static void ClearBackground();
	int WindowShouldClose();
	void FinishWindowCycle();
	void CloseWindow();

};
#endif // !WINDOW_H
