#include "TestScript.h"
#include "Game.h"
#include "TestScene.h"

TestScript::TestScript()
{
}

void TestScript::Start()
{
	cout << "Game script started" << endl;
}

void TestScript::Update()
{
	if (glfwGetKey(Window::window, GLFW_KEY_A))
	{
		cout << "fuck";
		TestScene* test = new TestScene();
		Game::LoadScene(*test);
	}
}

void TestScript::Stop()
{
}