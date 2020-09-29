
#include "BaseGame.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include "glew.h"
#include "glfw3.h"

BaseGame::BaseGame() {
	//ventana = new Window();
	//render = new Renderer();
}
BaseGame::~BaseGame() {

}

int BaseGame::StartWindow(int width, int height, const char* windowName )
{
	return ventana.Start(width, height, windowName);
}

void BaseGame::CloseWindow()
{
	ventana.CloseWindow();
}

void BaseGame::drawTriangle(CVec2 pos1, CVec2 pos2, CVec2 pos3)

{

	render.DrawTriangle(pos1, pos2, pos3);
}

void BaseGame::update()
{
	StartWindow(1280, 720, "Hello World");

	CVec2 pos1 = { -0.5f, -0.5f, BLUE };
	CVec2 pos2 = { 0.5f, -0.5f, BLUE };
	CVec2 pos3 = { 0.0f, 0.5f, BLUE };
	while (!ventana.WindowShouldClose())
	{
		ventana.ClearBackground();

		pos1 = { -0.5f, -0.5f, BLUE };
		pos2 = { 0.5f, -0.5f, BLUE };
		pos3 = { 0.0f, 0.5f, BLUE };
		render.DrawTriangle(pos1, pos2, pos3);


		pos1 = { -0.5f, 0.5f, RED };
		pos2 = { -0.6f, 0.6f, RED };
		pos3 = { -0.7f, 0.5f, RED };
		render.DrawTriangle(pos1, pos2, pos3);

		ventana.FinishWindowCycle();

	}
	CloseWindow();
	
}

