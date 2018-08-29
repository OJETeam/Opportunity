#include "Game.h"

vector<Object*> Game::objects;

void Game::Update()
{
	for (Object* obj : objects)
	{
		obj->Update();
	}
}

void Game::RenderObjects()
{
	for (Object* obj : objects)
	{
		obj->Render();
	}
}

void Game::AddObject(Object* object)
{
	if (!object)
		return;

	for (Object* obj : objects)
	{
		if (obj == object)
			return;
	}
	objects.push_back(object);
}