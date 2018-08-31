#include "Game.h"

vector<Object*> Game::objects;
map<Object*, bool> Game::objectsModifications;

void Game::Update()
{
	for (auto modifiedObj : objectsModifications)
	{
		if (!modifiedObj.first)
			continue;

		if (modifiedObj.second)
		{
			bool contained = false;

			for (Object* obj : objects)
			{
				if (obj == modifiedObj.first)
					contained = true;
			}
			if (!contained)
			{
				modifiedObj.first->OnCreate();
				objects.push_back(modifiedObj.first);
			}
		}
		else
		{
			for (int i = 0; i < objects.size(); i++)
			{
				if (objects[i] == modifiedObj.first)
				{
					objects[i]->OnDelete();
					objects.erase(objects.begin() + i);
					break;
				}
			}
		}
	}
	objectsModifications.clear();

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

	objectsModifications[object] = true;
}

void Game::RemoveObject(Object* object)
{
	objectsModifications[object] = false;
}