
#include "Window.h"

static unsigned int CompileShader(unsigned int type, const string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();  //  source.c_str() == &source[0]
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) //GL_FLASE es 0, pero así se entiende más
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length* sizeof(char));  // hace eso para poder hace char message[length], no entendí bien como
		glGetShaderInfoLog(id, length, &length, message);
		cout << "failed to compile " << (type == GL_VERTEX_SHADER ? "vertex " : "frangment ") << "shader" << endl;
		cout << message << endl;
		glDeleteShader(id);
		return 0;
	}

	return (id);

	//leer las funciones que empiezan con gl y hacer comentario de que hacen para tener a mano
}

static unsigned int CreateShader(const string& vertexShader, const string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader( GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glDeleteShader(vs);  // borra el shader para que no se haga un obj
	glDeleteShader(fs);	 // borra el shader para que no se haga un obj

	return program;
	//leer las funciones que empiezan con gl y hacer comentario de que hacen para tener a mano
}

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


