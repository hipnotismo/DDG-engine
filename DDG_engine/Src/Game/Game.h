
#ifndef GAME_H
#define GAME_H
#include "Game engine/Base game/baseGame.h"

class Game : public Window {

	
public:
	Game();
	~Game();
	BaseGame engine;
	int init();
};
#endif // !GAME_H
