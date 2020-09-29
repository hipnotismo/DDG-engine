
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
	void drawTriangle(CVec2 pos1, CVec2 pos2, CVec2 pos3);
	void update();
};
#endif // !BASEGAME_H
