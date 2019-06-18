#include "TestScene.h"
#include "Unit.h"
#include "ScriptLibrary.h"
#include "Game.h"

TestScene::TestScene()
{
}

TestScene::~TestScene()
{
}

void TestScene::Load()
{
	AbstractScript testScript = AbstractScript::FromFile("Test", "Test.cs");
	testScript.Compile();
	ScriptLibrary::AddScript(&testScript);

	Unit* test = new Unit(Vector2(200.0f, 200.0f), Model::Cube(50, Color::Blue, Vector2(0.5, 0.5)));
	test->parentPivot = Vector2(13, 44);
	test->setSize(Vector2(2.0f, 2.0f));
	test->AttachScript(testScript, true);
	AddObject(*test);

	Unit* test2 = new Unit(Vector2(150.0f, 200.0f), Model::Cube(30, Color::Green, Vector2(0.5, 0.5)));
	test2->SetParent(*test, false);
	test2->setDepth(1);
	AddObject(*test2);

	Unit* test3 = new Unit(Vector2(250.0f, 200.0f), Model::Cube(30, Color::Green, Vector2(0.5, 0.5)));
	test3->SetParent(*test, false);
	test3->setDepth(1);
	AddObject(*test3);

	Unit* test4 = new Unit(Vector2(200.0f, 250.0f), Model::Rectangle(Vector2(20, 40), Color::Green, Vector2(0.5, 0.5)));
	test4->SetParent(*test, false);
	test4->setDepth(1);
	AddObject(*test4);

	Unit* center = new Unit(Vector2(0, 0), Model::Rectangle(Vector2(20, 20), Color::Red, Vector2(0.5, 0.5)));
	AddObject(*center);
}

void TestScene::Unload()
{

}