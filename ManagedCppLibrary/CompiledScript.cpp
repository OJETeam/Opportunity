#include "CompiledScript.h"

ScriptManager::CompiledScript::CompiledScript(Type^ scriptType, Assembly^ assembly) : assembly(assembly), scriptType(scriptType)
{
	if (methodCreate == nullptr)
		methodCreate = scriptType->BaseType->GetMethod("create");
}

ScriptManager::IEventReceiver^ ScriptManager::CompiledScript::CreateScript(void* unit)
{
	Object^ script = Activator::CreateInstance(scriptType);
	Create^ createFunc = safe_cast<Create^>(methodCreate->CreateDelegate(Create::typeid, script));
	return createFunc(unit);
}