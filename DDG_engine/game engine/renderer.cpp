#include "renderer.h"

Renderer::Renderer() {

}
Renderer::~Renderer() {

}

void Renderer::DrawTriangle(Vec2 pos1, Vec2 pos2, Vec2 pos3) {
	//void Renderer::DrawTriangle() {
	/*
	float vertexs[6] = {
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.0f, 0.5f
	};*/
	float vertexs[6] = {
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.0f, 0.5f
	};
	
	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(vertexs), vertexs, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);


		glDrawArrays(GL_TRIANGLES, 0, 3);
		/*
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f );
	glVertex2f(0.0f, 0.5f );
	glEnd();*/
}