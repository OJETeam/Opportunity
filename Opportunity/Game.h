#pragma once

#include <vector>
#include <glad\glad.h>

#include "Window.h"
#include "Object.h"

class Game
{
private:
	static vector<Object*> objects;
public:
	static void Update();
	static void RenderObjects();
	static void AddObject(Object* object);
};