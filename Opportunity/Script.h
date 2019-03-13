#pragma once
#include "AbstractScript.h"

class Script
{
private:
	bool started;
	AbstractScript* script;
	Unit* unit;
public:
	Script(AbstractScript& script, Unit* unit);
	void Start();
};