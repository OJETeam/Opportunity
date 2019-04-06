#include "Game.h"
#include "Camera.h"
#include "ScriptLibrary.h"
#include "PivotVisualizer.h"

#define DEBUG_PIVOT

vector<Object*> Game::gameObjects;
vector<Object*> Game::guiObjects;
map<Object*, bool> Game::gameObjectsModifications;
map<Object*, bool> Game::guiObjectsModifications;

void Game::Update()
{
	UpdateArray(gameObjects, gameObjectsModifications);
	UpdateArray(guiObjects, guiObjectsModifications);
	Camera::Update(); //TODO add multiple cameras
	ScriptLibrary::Update();
}

void Game::UpdateArray(vector<Object*>& objects, map<Object*, bool>& objectsModifications)
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
	for (Object* obj : gameObjects)
	{
		obj->Render();
	}
	for (Object* obj : guiObjects)
	{
		obj->Render();
	}
}

void Game::AddObject(GameObject& object)
{
	if (!&object)
		return;

	gameObjectsModifications[&object] = true;

#ifdef DEBUG_PIVOT
	PivotVisualizer* pivotVisualizer = new PivotVisualizer(&object);
	gameObjectsModifications[pivotVisualizer] = true;
#endif
}

void Game::RemoveObject(GameObject& object)
{
	gameObjectsModifications[&object] = false;
}

void Game::AddObject(GuiObject& object)
{
	if (!&object)
		return;

	guiObjectsModifications[&object] = true;
}

void Game::RemoveObject(GuiObject& object)
{
	guiObjectsModifications[&object] = false;
}