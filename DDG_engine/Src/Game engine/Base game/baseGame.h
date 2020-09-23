
#ifndef BASEGAME_H
#define BASEGAME_H

#include "Game engine/Export/export.h"

#include "Game engine/Window/window.h"
#include "Game engine/Renderer/renderer.h"
#include "Game engine/Global/global.h"


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
