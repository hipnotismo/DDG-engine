#ifndef BASEGAME_H
#define BASEGAME_H

#include <iostream>
#include "export.h"
#include "window.h"
#include "renderer.h"

class ENGINE_API BaseGame { // consultar
	Window* window;
	Renderer* renderer;
public:
	BaseGame();
	~BaseGame();
	int compileShader(int type, const std::string& source);
	int createShader(const std::string& vertexShader, const std::string& fragmentShader);
	int init();
};
#endif // !BASEGAME_H

/*
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
*/