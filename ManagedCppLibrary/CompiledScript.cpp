#include "CompiledScript.h"

ScriptManager::CompiledScript::CompiledScript(Assembly^ assembly) : assembly(assembly)
{
}

Engine::Script^ ScriptManager::CompiledScript::CreateScript(void* unit)
{
	Engine::Script^ script = (Engine::Script^)Activator::CreateInstance(scriptType);
	script->unit = unit;
	script->Start();
	return script;
}