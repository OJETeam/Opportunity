#include "CompilerApi.h"
#include "Manager.h"

API bool ScriptManager::CompilerApi::CompileScript(std::string text)
{
	String^ clrStr = gcnew String(text.c_str());
	return Manager::CompileScript(clrStr);
}

void ScriptManager::CompilerApi::RunScript(void* unit)
{
	Manager::RunScript(unit);
}

void ScriptManager::CompilerApi::Update()
{
	Manager::Update();
}