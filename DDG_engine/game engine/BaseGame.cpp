
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

int BaseGame::StartWindow(int width, int height, const char* windowName )
{
	return ventana.Start(width, height, windowName);
}

void BaseGame::CloseWindow()
{
	ventana.CloseWindow();
}

void BaseGame::drawTriangle(Vec2 pos1, Vec2 pos2, Vec2 pos3)

{

	render.DrawTriangle(pos1, pos2, pos3);
}

