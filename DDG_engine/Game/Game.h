#ifndef GAME_H
#define GAME_H
#include "BaseGame.h"
#include "Window.h"

class Game : public Window {

public:
	Game();
	~Game();
	int init();
};
#endif // !GAME_H
