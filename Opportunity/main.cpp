#include <iostream>
#include <glad/glad.h>
#include "Window.h"
#include "Game.h"
#include "Model.h"
#include "Object.h"
#include "Cube.h"
#include "Player.h"
#include "Script.h"
#include "Api.h"

using namespace std;

__declspec(dllexport) void Run()
{
	Window::Init();
	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
		cout << "Failed to initialize GLAD" << endl;
	else
		cout << "GLAD initialized" << endl;

	glViewport(0, 0, Window::width, Window::height);
	glClearColor(1, 0, 1, 1);

	Script testScript = Script::FromFile("test.cs", "test.cs");
	testScript.Compile();

	Unit testUnit1(Vector2(13, 44));
	Unit testUnit2(Vector2(55, 66));
	testUnit2.scripts.push_back(&testScript);
	Game::AddObject(&testUnit2);
	testScript.RunScript(&testUnit2);

	Cube test(Vector2(10, 10), 100, Color::Green);
	Game::AddObject(&test);

	Player player = Player(Vector2(0, 0), Model::Cube(50, Color::Green));
	Game::AddObject(&player);

	while (!Window::Exit)
	{
		glClear(GL_COLOR_BUFFER_BIT);

		Game::Update();
		Game::RenderObjects();
		Window::PostRender();
	}

	Window::Terminate();
}