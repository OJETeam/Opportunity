#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include "GameObject.h"
#include "GuiObject.h"
#include "IGameScript.h"

using namespace std;

class Scene
{
private:
	vector<Object*> gameObjects;
	vector<Object*> guiObjects;
	vector<IGameScript*> scripts;
	map<Object*, bool> gameObjectsModifications;
	map<Object*, bool> guiObjectsModifications;
	map<IGameScript*, bool> scriptsModifications;
	bool updateDepth;

	void Update();
	void UpdateArray(vector<Object*>& objects, map<Object*, bool>& objectsModifications);
	void RenderObjects();

	friend class Game;
protected:
	virtual void Load() = 0;
	virtual void Unload() = 0;
public:
	Scene();
	virtual ~Scene();
	void AddObject(GameObject& object);
	void RemoveObject(GameObject& object);
	void AddObject(GuiObject& object);
	void RemoveObject(GuiObject& object);
	void AddScript(IGameScript& script);
	void RemoveScript(IGameScript& script);
	void UpdateDepth();

	vector<Object*>::const_iterator gameObjectsBegin();
	vector<Object*>::const_iterator gameObjectsEnd();
	vector<Object*>::const_iterator guiObjectsBegin();
	vector<Object*>::const_iterator guiObjectsEnd();
};