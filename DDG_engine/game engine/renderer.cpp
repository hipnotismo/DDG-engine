#include "renderer.h"

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
		char* message = (char*)alloca(length * sizeof(char));  // hace eso para poder hace char message[length], no entendí bien como
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
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
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

Renderer::Renderer() {
	i = 0;

	
}
Renderer::~Renderer() {

}

void Renderer::DrawTriangle(CVec2 pos1, CVec2 pos2, CVec2 pos3) {
	
	float vertexs[18] = {
		pos1.x, pos1.y, pos1.color.R, pos1.color.G , pos1.color.B , pos1.color.A,
		pos2.x, pos2.y, pos2.color.R, pos2.color.G , pos2.color.B , pos2.color.A,
		pos3.x, pos3.y, pos3.color.R, pos3.color.G , pos3.color.B , pos3.color.A
	};
	
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(vertexs), vertexs, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void *)(2*sizeof(float)));

	string vertexShader =
		"#version 330 core  \n"
		"\n"
		"layout(location = 0) in vec4 position;\n"
		"layout(location = 1) in vec4 customColor;\n"
		" out vec4 color;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = position; \n"
		"	color = customColor; \n"
		"}\n";

	string fragmentShader =
		"#version 330 core  \n"
		"\n"
		"in vec4 color;\n"
		"out vec4 outColor;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	outColor = color; \n"
		"}\n";

		unsigned int shader = CreateShader(vertexShader, fragmentShader);
		glUseProgram(shader);


		glDrawArrays(GL_TRIANGLES, 0, 3);
		buffer = NULL;
}


