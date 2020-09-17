
#include "Window.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include "glew.h"
#include "glfw3.h"

Window::Window() {

}
Window::~Window() {

}
int Window::StartWindow(int width, int height, const char* windowName) {
	

	GLFWwindow* window;
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

	float vertexs[6] = {
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.0f, 0.5f,
	};

	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(vertexs), vertexs, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	//Loop until the user closes the window /
	while (!glfwWindowShouldClose(window))
	{
		ClearBackground();
		// Render here /

		glDrawArrays(GL_TRIANGLES, 0, 3);

		// Swap front and back buffers /
		glfwSwapBuffers(window);


		// Poll for and process events 
		glfwPollEvents();
		
	}


}

void Window::ClearBackground()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

int Window::WindowShouldClose()
{
//	return glfwWindowShouldClose(window);
	return false;
}

void Window::FinishWindowCycle()
{
	// Swap front and back buffers /
	//	glfwSwapBuffers(window);


		// Poll for and process events 
		glfwPollEvents();
}

void Window::CloseWindow()
{
	glfwTerminate();
}


