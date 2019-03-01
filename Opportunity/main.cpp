#include <iostream>
#include <glad/glad.h>
#include "Window.h"
#include "Game.h"
#include "Model.h"
#include "Object.h"
#include "Cube.h"
#include "Player.h"
#include "AbstractScript.h"
#include "Api.h"
#include "ScriptLibrary.h"
#include "Unit.h"

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

	//AbstractScript testScript = AbstractScript::FromFile("test.cs", "test.cs");
	//testScript.Compile();
	//ScriptLibrary::AddScript(&testScript);

	Cube test(Vector2(0, 0), 50, Color::Green);
	Game::AddObject(&test);

	//Player player = Player(Vector2(1, 0), Model::Cube(0.1, Color::Green));
	//Game::AddObject(&player);

	while (!Window::Exit)
	{
		glClear(GL_COLOR_BUFFER_BIT);

		Game::Update();
		ScriptLibrary::Update();
		Game::RenderObjects();
		Window::PostRender();
	}

	Window::Terminate();
}