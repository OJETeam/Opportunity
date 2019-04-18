#include "TestScript.h"
#include "Game.h"
#include "TestScene.h"
#include "Input.h"

TestScript::TestScript()
{
}

void TestScript::Start()
{
	cout << "Game script started" << endl;
}

void TestScript::Update()
{
	if (Input::IsKeyClicked(GLFW_KEY_A))
	{
		cout << "fuck" << endl;
		TestScene* test = new TestScene();
		Game::LoadScene(*test);
	}
}

void TestScript::Stop()
{
}