#pragma once

#include <vector>
#include <glad/glad.h>
#include <map>

#include "Window.h"
#include "GameObject.h"
#include "GuiObject.h"

class Game
{
private:
	static vector<Object*> gameObjects;
	static vector<Object*> guiObjects;
	static map<Object*, bool> gameObjectsModifications;
	static map<Object*, bool> guiObjectsModifications;
public:
	static void Update();
	static void UpdateArray(vector<Object*>& objects, map<Object*, bool>& objectsModifications);
	static void RenderObjects();
	static void AddObject(GameObject& object);
	static void RemoveObject(GameObject& object);
	static void AddObject(GuiObject& object);
	static void RemoveObject(GuiObject& object);
};