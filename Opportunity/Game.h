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
	static void AddObject(GameObject& object);
	static void RemoveObject(GameObject& object); //TODO too many proxy methods. Allow direct access to scene
	static void AddObject(GuiObject& object);
	static void RemoveObject(GuiObject& object);
	static void AddScript(IGameScript& script);
	static void RemoveScript(IGameScript& script);
	static void UpdateDepth();
};