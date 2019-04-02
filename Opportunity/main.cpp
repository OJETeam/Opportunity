#include <iostream>
#include <glad/glad.h>
#include "Window.h"
#include "Game.h"
#include "Model.h"
#include "Object.h"
#include "Cube.h"
#include "AbstractScript.h"
#include "Api.h"
#include "ScriptLibrary.h"
#include "Unit.h"
#include "Time.h"
#include "GuiButton.h"

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

	AbstractScript testScript = AbstractScript::FromFile("Test", "Test.cs");
	testScript.Compile();
	ScriptLibrary::AddScript(&testScript);

	Unit test(Vector2(400.0f, 400.0f), Model::Cube(50, Color::Blue, Vector2(0.5, 0.5)));
	test.setSize(Vector2(2.0f, 2.0f));
	test.AttachScript(testScript, true);
	Game::AddObject(test);

	GuiButton obj = GuiButton(Vector2(0.5, 0), Vector2(0.5, 0.1), Color(0.5, 0.5, 0), Vector2(0, 0));
	Game::AddObject(obj);

	//GuiObject j = GuiObject(Vector2(9, 9), Model::Cube(50, Color::Blue, Vector2(0.5, 0.5)));
	//j.SubscribeClick([]() mutable -> void {return; });

	Time::Start();
	while (!Window::Exit)
	{
		Time::Update();
		glClear(GL_COLOR_BUFFER_BIT);

		Game::Update();
		Game::RenderObjects();
		Window::PostRender();
	}

	Window::Terminate();
}