#include "Scene.h"

//#define DEBUG_PIVOT

Scene::Scene() : updateDepth(true)
{
}

Scene::~Scene()
{
}

void Scene::Update()
{
	UpdateArray(gameObjects, gameObjectsModifications);
	UpdateArray(guiObjects, guiObjectsModifications);

	for (auto modifiedScript : scriptsModifications)
	{
		if (!modifiedScript.first)
			continue;

		if (modifiedScript.second)
		{
			bool contained = false;

			for (IGameScript* script : scripts)
			{
				if (script == modifiedScript.first)
					contained = true;
			}
			if (!contained)
			{
				modifiedScript.first->Start();
				scripts.push_back(modifiedScript.first);
			}
		}
		else
		{
			for (int i = 0; i < scripts.size(); i++)
			{
				if (scripts[i] == modifiedScript.first)
				{
					scripts[i]->Stop();
					scripts.erase(scripts.begin() + i);
					break;
				}
			}
		}
	}
	scriptsModifications.clear();

	for (IGameScript* script : scripts)
	{
		script->Update();
	}
}

void Scene::UpdateArray(vector<Object*>& objects, map<Object*, bool>& objectsModifications)
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
				updateDepth = true;
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

	if (updateDepth)
	{
		sort(objects.begin(), objects.end(), [](const Object * first, const Object * second) -> bool { return first->getDepth() > second->getDepth(); });
		updateDepth = false;
	}

	for (Object* obj : objects)
	{
		obj->Update();
	}
}

void Scene::RenderObjects()
{
	for (Object* obj : guiObjects)
	{
		if (obj->visible)
			obj->Render();
	}
	for (Object* obj : gameObjects)
	{
		if (obj->visible)
			obj->Render();
	}
}

void Scene::AddObject(GameObject& object)
{
	gameObjectsModifications[&object] = true;

#ifdef DEBUG_PIVOT
	PivotVisualizer* pivotVisualizer = new PivotVisualizer(&object);
	gameObjectsModifications[pivotVisualizer] = true;
#endif
}

void Scene::RemoveObject(GameObject& object)
{
	gameObjectsModifications[&object] = false;
}

void Scene::AddObject(GuiObject& object)
{
	guiObjectsModifications[&object] = true;
}

void Scene::RemoveObject(GuiObject& object)
{
	guiObjectsModifications[&object] = false;
}

void Scene::AddScript(IGameScript& script)
{
	scriptsModifications[&script] = true;
}

void Scene::RemoveScript(IGameScript& script)
{
	scriptsModifications[&script] = false;
}

void Scene::UpdateDepth()
{
	updateDepth = true;
}
