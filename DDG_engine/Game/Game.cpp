
#include "game.h"
Game::Game() {

}
Game::~Game() {

}

int Game::init() {
	engine.ventana.StartWindow(1280, 720, "Hello World");
	return 0;
}
