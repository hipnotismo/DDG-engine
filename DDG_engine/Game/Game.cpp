
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

		CVec2 pos1 = { -0.5f, -0.5f, BLUE };
		CVec2 pos2 = { 0.5f, -0.5f, BLUE };
		CVec2 pos3 = { 0.0f, 0.5f, BLUE };
		engine.render.DrawTriangle(pos1, pos2, pos3);


		
		pos1 = { -0.5f, 0.5f, RED };
		pos2 = { -0.6f, 0.6f, RED };
		pos3 = { -0.7f, 0.5f, RED };
		engine.render.DrawTriangle(pos1, pos2, pos3);

		engine.ventana.FinishWindowCycle();
	
	}
	engine.CloseWindow();
	return 0;
}
