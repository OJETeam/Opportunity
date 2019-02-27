#include "Script.h"

Script::Script(AbstractScript* script, Unit* unit) : script(script), unit(unit)
{
	started = false;
}

void Script::Start()
{
	script->RunScript(unit);
	started = true;
}