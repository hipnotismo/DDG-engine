
#include "Window.h"


Window::Window() {

}
Window::~Window() {

}

int Window::Start(int width, int height, const char* windowName) 
{
	//Initialize the library /
	if (!glfwInit())
		return -1;

	// Create a windowed mode window and its OpenGL context /
	window = glfwCreateWindow(width, height, windowName, NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current /
	glfwMakeContextCurrent(window);

	glewInit();

	std::cout << glGetString(GL_VERSION) << std::endl;
}

void Window::ClearBackground()
{
	// Swap front and back buffers 
	glClear(GL_COLOR_BUFFER_BIT);
}

int Window::WindowShouldClose()
{
	return glfwWindowShouldClose(window);	
}

void Window::FinishWindowCycle()
{
		// Swap front and back buffers /
		glfwSwapBuffers(window);

		// Poll for and process events 
		glfwPollEvents();
}

void Window::CloseWindow()
{
	glfwTerminate();
}


