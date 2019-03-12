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
#include "Time.h"

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

	Cube test(Vector2(100.0f, 100.0f), 50, Color::Green);
	test.scale = Vector2(2.0f, 2.0f);
	Game::AddObject(&test);

	Time::Start();
	while (!Window::Exit)
	{
		Time::Update();
		glClear(GL_COLOR_BUFFER_BIT);

		Game::Update();
		ScriptLibrary::Update();
		Game::RenderObjects();
		Window::PostRender();
	}

	Window::Terminate();
}