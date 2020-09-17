
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

int BaseGame::StartWindow(int width, int height, const char* windowName)
{
	return ventana.StartWindow(width, height, windowName);
}

void BaseGame::CloseWindow()
{
	ventana.CloseWindow();
}

void BaseGame::drawTriangle()
{
	render.DrawTriangle();
}

