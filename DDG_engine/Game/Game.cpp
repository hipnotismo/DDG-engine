
#include "game.h"
Game::Game() {

}
Game::~Game() {

}

void mouse_button_callback(GLFWwindow* window, int button, int action)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		double xpos, ypos;
		//getting cursor position
		glfwGetCursorPos(window, &xpos, &ypos);
		cout << "Cursor Position at (" << xpos << " : " << ypos << endl;
	}
}

int Game::init() {

	engine.StartWindow(1280, 720, "Hello World");

	CVec2 pos1 = { -0.5f, -0.5f, BLUE };
	CVec2 pos2 = { 0.5f, -0.5f, BLUE };
	CVec2 pos3 = { 0.0f, 0.5f, BLUE };
	while (!engine.ventana.WindowShouldClose())
	{
		mouse_button_callback(engine.ventana.window, GLFW_MOUSE_BUTTON_LEFT, glfwGeta);
		engine.ventana.ClearBackground();
		
		pos1 = { -0.5f, -0.5f, BLUE };
		pos2 = { 0.5f, -0.5f, BLUE };
		pos3 = { 0.0f, 0.5f, BLUE };
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
