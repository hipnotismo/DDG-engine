
#include "game.h"
Game::Game() {

}
Game::~Game() {

}

int Game::init() {
	engine.StartWindow(1280, 720, "Hello World");
	
	engine.CloseWindow();
	return 0;
}
