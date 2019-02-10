#include "CompiledScript.h"

ScriptManager::CompiledScript::CompiledScript(Type^ scriptType, Assembly^ assembly) : scriptType(scriptType), assembly(assembly)
{
}

Engine::Script^ ScriptManager::CompiledScript::CreateScript(void* unit)
{
	Engine::Script^ script = (Engine::Script^)Activator::CreateInstance(scriptType);
	script->unit = unit;
	return script;
}