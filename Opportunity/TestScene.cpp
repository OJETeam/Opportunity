#include "TestScene.h"
#include "Unit.h"
#include "ScriptLibrary.h"
#include "Game.h"
#include "GuiSprite.h"
#include "PolyCollider.h"
#include "TestGameObject.h"

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

	Unit* testUnit = new Unit(Vector2(200.0f, 200.0f), Model::Cube(50, Color::Blue, Vector2(0.5, 0.5)));
	testUnit->collider = PolyCollider::Cube(50.0f);
	testUnit->setSize(Vector2(2.0f, 2.0f));
	testUnit->AttachScript(testScript, true);
	AddObject(*testUnit);

	TestGameObject* test2 = new TestGameObject(Vector2(150.0f, 200.0f), Model::Cube(30, Color::Green, Vector2(0.5, 0.5)));
	test2->collider = PolyCollider::Cube(30.0f);
	test2->SetParent(*testUnit, false);
	test2->setDepth(1);
	AddObject(*test2);

	TestGameObject* test3 = new TestGameObject(Vector2(250.0f, 200.0f), Model::Cube(30, Color::Green, Vector2(0.5, 0.5)));
	test3->collider = PolyCollider::Cube(30.0f);
	test3->SetParent(*testUnit, false);
	test3->setDepth(1);
	AddObject(*test3);

	TestGameObject* test4 = new TestGameObject(Vector2(200.0f, 250.0f), Model::Rectangle(Vector2(20, 40), Color::Green, Vector2(0.5, 0.5)));
	test4->collider = PolyCollider::Rectangle(Vector2(20, 40));
	test4->SetParent(*testUnit, false);
	test4->setDepth(1);
	AddObject(*test4);

	testUnit->setPosition(Vector2(200.0f, 200.0f));
	testUnit->setRotation(glm::pi<float>() / 3);

	Unit* center = new Unit(Vector2(0, 0), Model::Rectangle(Vector2(20, 20), Color::Red, Vector2(0.5, 0.5)));
	AddObject(*center);

	GuiSprite* testSprite = new GuiSprite(Vector2(0.5, 0), Vector2(0.5, 0.1), Color::Blue, Vector2(0, 0));
	AddObject(*testSprite);
}

void TestScene::Unload()
{

}