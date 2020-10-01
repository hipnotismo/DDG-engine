#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 customColor;
out vec4 color;

void main()
{
	gl_Position = position;
	color = customColor;
};


