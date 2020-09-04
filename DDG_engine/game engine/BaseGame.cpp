#include "BaseGame.h"
#include <stdlib.h>
#include <iostream>
#include "glew.h"
#include "glfw3.h"
BaseGame::BaseGame() {
	window = new Window();
	renderer = NULL;
	renderer = new Renderer();
}
BaseGame::~BaseGame() {
	if (window != NULL)
		delete window;
	if (renderer != NULL)
		delete renderer;
}

int BaseGame::compileShader(int type, const char*& source) {
	int id = glCreateShader(type);
	const char* src = source;
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

int BaseGame::createShader(const GLchar*& vertexShader, const GLchar*& fragmentShader) {
	int program = glCreateProgram();
	int vertexshader = compileShader(GL_VERTEX_SHADER, vertexShader);
	int fragmentshader = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vertexshader);
	glAttachShader(program, fragmentshader);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vertexshader);
	glDeleteShader(fragmentshader);

	return program;
}
int BaseGame::init() {
	GLFWwindow* newWindow;

	window->StartWindow(800, 600, "Graphics Engine", newWindow);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current /
	glfwMakeContextCurrent(newWindow);

	glewExperimental = GL_TRUE;
	glewInit();

	renderer->CreateTriangle();

	const GLchar* vertexShader = R"glsl(
		#version 150 core
		
		in vec2 position;
		in vec3 customColor;
		out vec3 color;
		void main()
		{
		gl_Position = vec4(position,0.0,1.0);
		}
)glsl";

	const GLchar* fragmentShader = R"glsl(
		#version 150 core
		
		out vec4 outColor;
		
		void main()
		{
		outColor = vec4(1.0, 1.0, 0.0, 1.0);
		}
)glsl";

	int shader = createShader(vertexShader, fragmentShader);
	glUseProgram(shader);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	//Loop until the user closes the window /
	while (!glfwWindowShouldClose(newWindow))
	{
		// Render here /
		glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		renderer->DrawTriangle();

		// Swap front and back buffers /
		glfwSwapBuffers(newWindow);

		// Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

/*
#include "BaseGame.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include "glew.h"
#include "glfw3.h"

BaseGame::BaseGame() {

}
BaseGame::~BaseGame() {

}
int BaseGame::StartWindow(int width, int height, const char* windowName) {
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

	//Loop until the user closes the window /
	while (!glfwWindowShouldClose(window))
	{ 
		// Render here /
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap front and back buffers /
		glfwSwapBuffers(window);

		// Poll for and process events 
		glfwPollEvents();
	}

	glfwTerminate();
}
*/