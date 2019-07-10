#pragma once

#include <vector>
#include <glad/glad.h>
#include <map>

#include "Window.h"
#include "GameObject.h"
#include "GuiObject.h"
#include "Scene.h"
#include "IGameScript.h"

class Game
{
private:
	static Scene* loadedScene;
public:
	static void Update();
	static void Render();
	static void Start(Scene& scene, IGameScript& script);
	static void LoadScene(Scene& scene);
	static Scene* GetScene();
	static void UpdateDepth();
};