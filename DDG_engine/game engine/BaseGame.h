
#ifndef BASEGAME_H
#define BASEGAME_H

#include "export.h"

class ENGINE_API BaseGame {

public:
	BaseGame();
	~BaseGame();
	int StartWindow(int width, int height, const char* windowName);
};
#endif // !BASEGAME_H
