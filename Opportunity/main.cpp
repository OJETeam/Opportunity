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

void InitTestObjects(); //TODO test

__declspec(dllexport) void Run()
{
	Window::Init();
	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
		cout << "Failed to initialize GLAD" << endl;
	else
		cout << "GLAD initialized" << endl;

	glViewport(0, 0, Window::width, Window::height);
	glClearColor(1, 0, 1, 1);

	InitTestObjects();

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

void InitTestObjects()
{
	AbstractScript testScript = AbstractScript::FromFile("Test", "Test.cs");
	testScript.Compile();
	ScriptLibrary::AddScript(&testScript);

	Unit* test = new Unit(Vector2(200.0f, 200.0f), Model::Cube(50, Color::Blue, Vector2(0.5, 0.5)));
	test->setSize(Vector2(2.0f, 2.0f));
	test->AttachScript(testScript, true);
	Game::AddObject(*test);

	Unit* test2 = new Unit(Vector2(150.0f, 200.0f), Model::Cube(30, Color::Green, Vector2(0.5, 0.5)));
	test2->SetParent(*test, false);
	Game::AddObject(*test2);

	Unit* test3 = new Unit(Vector2(250.0f, 200.0f), Model::Cube(30, Color::Green, Vector2(0.5, 0.5)));
	test3->SetParent(*test, false);
	Game::AddObject(*test3);

	Unit* test4 = new Unit(Vector2(200.0f, 250.0f), Model::Rectangle(Vector2(20, 40), Color::Green, Vector2(0.5, 0.5)));
	test4->SetParent(*test, false);
	Game::AddObject(*test4);

	GuiButton* obj = new GuiButton(Vector2(0.5, 0), Vector2(0.5, 0.1), Color(0.5, 0.5, 0), Vector2(0, 0));
	Game::AddObject(*obj);
}