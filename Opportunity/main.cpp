#include <iostream>

#include <glad\glad.h>
#include "Window.h"
#include "Game.h"
#include "Model.h"
#include "Object.h"
#include "Cube.h"

using namespace std;

int main()
{
	Window::Init();
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		cout << "Failed to initialize GLAD" << endl;
	else
		cout << "GLAD initialized" << endl;

	glViewport(0, 0, Window::width, Window::height);
	glClearColor(1, 0, 1, 1);

	Cube test(Vector2(0, 0), 1, Color::Green);
	Game::AddObject(&test);

	while (!Window::Exit)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		Game::Update();
		Game::RenderObjects();
		Window::PostRender();
	}

	Window::Terminate();
}