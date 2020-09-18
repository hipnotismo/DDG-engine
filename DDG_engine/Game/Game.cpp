
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


		
		Vec2 pos4 = { -0.5f, 0.5f };
		Vec2 pos5 = { -0.6f, 0.6f };
		Vec2 pos6 = { -0.7f, 0.5f };
		engine.render.DrawTriangle(pos4, pos5, pos6);

		engine.ventana.FinishWindowCycle();
		engine.render.finishRenderCycle();
	
	}
	engine.CloseWindow();
	return 0;
}
