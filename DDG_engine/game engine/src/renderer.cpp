#include "renderer.h"

static ShadersSource ParseShader(const string& filepath)
{
	ifstream stream(filepath, ios::in);
	string line;
	stringstream ss[2];
	ShadersType type = NONE;
	while (getline(stream, line))
	{
		if (line.find("#shader") != string::npos)
		{
			if (line.find("vertex") != string::npos)
			{
				type = VERTEX;
			}
			else if (line.find("fragment") != string::npos)
			{
				type = FRAGMENT;
			}
		}
		else
		{
			ss[(int)type] << line << endl;
		}
	}
	return { ss[0].str(), ss[1].str() };
}

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
		int length = source.size();
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		
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
	
	glGenBuffers(1, &buffer); //importante
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(vertexs), vertexs, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);  //importante
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0); //importante

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void *)(2*sizeof(float)));


	ShadersSource source = ParseShader("../res/shaders/Basic.shader");
	cout << "VERTEX"<< endl;
	cout << source.vertexSource << endl;
	cout << "FRAGMENT" << endl;
	cout << source.fragmentSource << endl;
		//unsigned int shader = CreateShader(vertexShader, fragmentShader);
		//glUseProgram(shader);


		glDrawArrays(GL_TRIANGLES, 0, 3); //importante
		buffer = NULL;
}


/*

static ShadersSource ParseShader(const string& filepath)
{
	ifstream stream(filepath);
	char line[40] = "";
	string line2;
	stringstream ss[2];
	ShadersType type = NONE;
	stream.exceptions(ifstream::failbit | ifstream::badbit);
	try
	{
		stream.open(filepath, ios::in);
		std::cout << "abriendo el archivo shaders" << endl;
		try
		{
			std::cout << "leyendo todo el archivo shaders" << endl;
			stream.getline(line, 20);
			line2 = line;
			while (!stream.eof())
			{
				if (line2.find("#shader") != string::npos)
				{
					if (line2.find("vertex") != string::npos)
					{
						type = VERTEX;
					}
					else if (line2.find("fragment") != string::npos)
					{
						type = FRAGMENT;
					}
				}
				else
				{
					ss[(int)type] << line << endl;
				}
				std::cout << line << endl;
				stream.getline(line, 20);
				line2 = line;
			}
			return { ss[0].str(), ss[1].str() };
		}
		catch (ifstream::failure& e)
		{
			if (stream.bad())
				std::cout << "hubo un error al leer el archivo shaders";
		}
		try { stream.close(); std::cout << "cerrando el archivo Scores" << endl; }
		catch (ifstream::failure& e) { if (stream.fail())std::cout << "Hubo un error al cerrar el archivo Scores"; }
	}
	catch (ifstream::failure& e)
	{ if (stream.fail())std::cout << "Hubo un error al abrir el archivo Scores";
	}
	catch (...)
	{
		std::cout << "error desconocido" << endl;
	}
}

*/