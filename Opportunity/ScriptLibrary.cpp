#include "ScriptLibrary.h"
#include "CompilerApi.h"

vector<AbstractScript*> ScriptLibrary::scripts;

void ScriptLibrary::AddScript(AbstractScript* script)
{
	scripts.push_back(script);
}

void ScriptLibrary::RemoveScript(AbstractScript* script)
{
	scripts.erase(find(scripts.begin(), scripts.end(), script));
}

void ScriptLibrary::Update()
{
	ScriptManager::CompilerApi::Update();
}