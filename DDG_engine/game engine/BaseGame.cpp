
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

