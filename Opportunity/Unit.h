#pragma once
#include <vector>
#include "Object.h"
#include "AbstractScript.h"
#include "Script.h"

class Unit : public Object
{
private:
	vector<Script> scripts;
public:
	Unit(Vector2 position);
	~Unit();
	void AttachScript(AbstractScript* script, bool run);
	void Update() override;
};