#include "game.h"
#include "Window.h"
int main() {
	Game* game = new Game();
	game->init();
	delete game;
}