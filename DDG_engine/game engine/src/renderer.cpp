#include "renderer.h"


static unsigned int CompileShader(unsigned int type, const string& source)
{
	unsigned int id = glCreateShader(type);

	string sourceShaderCode;
	ifstream sourceShaderFile;
	sourceShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
	try
	{
		sourceShaderFile.open(source);
		stringstream sourceShaderStream;

		sourceShaderStream << sourceShaderFile.rdbuf();
		sourceShaderFile.close();

		sourceShaderCode = sourceShaderStream.str();
	}
	catch (ifstream::failure& e)
	{
		cout << "error de lectura del shader" << endl;
	}
	
	const char* src = sourceShaderCode.c_str();
	
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

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

void Renderer::DrawTriangle(CVec4 pos1, CVec4 pos2, CVec4 pos3) {
	
	float vertexs[24] = {
		pos1.x, pos1.y, pos1.z, pos1.w, pos1.color.R, pos1.color.G , pos1.color.B , pos1.color.A,
		pos2.x, pos2.y, pos2.z, pos2.w, pos2.color.R, pos2.color.G , pos2.color.B , pos2.color.A,
		pos3.x, pos3.y, pos3.z, pos3.w, pos3.color.R, pos3.color.G , pos3.color.B , pos3.color.A
	};
	
	glGenBuffers(1, &buffer); //importante
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(vertexs), vertexs, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);  //importante
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 8, 0); //importante

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void *)(4*sizeof(float)));


	unsigned int shader = CreateShader("res/shader/vertex.shader", "res/shader/fragment.shader");

	glUseProgram(shader);

	glDrawArrays(GL_TRIANGLES, 0, 3); //importante
	buffer = NULL;
}


