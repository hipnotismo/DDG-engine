
#include "game.h"
Game::Game() {

}
Game::~Game() {

}

int Game::init() {

	engine.StartWindow(1280, 720, "Hello World");
	while (!engine.ventana.WindowShouldClose())
	{
		engine.ventana.ClearBackground();

		Vec2 pos1 = { -0.5f, -0.5f };
		Vec2 pos2 = { 0.5f, -0.5f };
		Vec2 pos3 = { 0.0f, 0.5f };
		engine.render.DrawTriangle(pos1, pos2, pos3);


		//engine.drawTriangle();
		engine.ventana.FinishWindowCycle();
	
	}
	engine.CloseWindow();
	return 0;
}
