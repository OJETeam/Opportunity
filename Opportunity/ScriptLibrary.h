#pragma once
#include <vector>
#include "AbstractScript.h"

using namespace std;

class ScriptLibrary //TODO implement this class after ingame scriptwriting is ready
{
private:
	static vector<AbstractScript*> scripts;
public:
	static void AddScript(AbstractScript* script);
	static void RemoveScript(AbstractScript* script);
	static void Update();
};