#include "CompiledScript.h"

ScriptManager::CompiledScript::CompiledScript(Type^ scriptType, Assembly^ assembly) : assembly(assembly), scriptType(scriptType)
{
}

Engine::Script^ ScriptManager::CompiledScript::CreateScript(void* unit)
{
	Engine::Script^ script = (Engine::Script^)Activator::CreateInstance(scriptType);
	script->unit = unit;
	return script;
}