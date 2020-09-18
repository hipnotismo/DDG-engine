
#ifndef BASEGAME_H
#define BASEGAME_H

#include "export.h"

#include "Window.h"
#include "renderer.h"

#include "Global.h"


class ENGINE_API BaseGame {
	
public:
	BaseGame();
	~BaseGame();
	Window ventana;
	Renderer render;
	int StartWindow(int width, int height, const char* windowName);
	void CloseWindow();
	void drawTriangle(Vec2 pos1, Vec2 pos2, Vec2 pos3);

};
#endif // !BASEGAME_H
