#include <iostream>
#include <glad/glad.h>
#include "Window.h"
#include "Game.h"
#include "Cube.h"
#include "AbstractScript.h"
#include "Time.h"
#include "TestScene.h"
#include "TestScript.h"

using namespace std;

Scene&& gameScene = TestScene(); //TODO move somewhere
IGameScript&& gameScript = TestScript();

__declspec(dllexport) void Run()
{
	Window::Init();
	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
		cout << "Failed to initialize GLAD" << endl;
	else
		cout << "GLAD initialized" << endl;

	glViewport(0, 0, Window::width, Window::height);
	glClearColor(1, 0, 1, 1);
	glEnable(GL_DEPTH_TEST);

	Game::Start(gameScene, gameScript);
	Time::Start();
	while (!Window::Exit)
	{
		Time::Update();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Game::Update();
		Game::Render();
		Window::PostRender();
	}

	Window::Terminate();
}