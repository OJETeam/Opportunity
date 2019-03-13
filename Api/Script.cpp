#include "Script.h"

Engine::Script::Script() : unit(nullptr)
{

}

IEventReceiver^ Engine::Script::create(void* unit)
{
	/*Script^ script = safe_cast<Script^>(Activator::CreateInstance(scriptType));
	script->unit = unit;
	script->Unit = gcnew Engine::Unit(unit);

	return safe_cast<ScriptManager::IEventReceiver^>(script);*/
	
	this->unit = unit;
	this->Unit = gcnew Engine::Unit(unit);

	return safe_cast<IEventReceiver^>(this);
}