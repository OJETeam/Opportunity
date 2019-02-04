#pragma once

#include <vector>
#include <glad/glad.h>
#include <map>

#include "Window.h"
#include "Object.h"

class Game
{
private:
	static vector<Object*> objects;
	static map<Object*, bool> objectsModifications;
public:
	static void Update();
	static void RenderObjects();
	static void AddObject(Object* object);
	static void RemoveObject(Object* object);
};