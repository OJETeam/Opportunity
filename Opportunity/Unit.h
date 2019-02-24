#pragma once
#include <vector>
#include "Object.h"
#include "AbstractScript.h"
#include "Script.h"

class AbstractScript;

class Unit : public Object
{
public:
	vector<Script> scripts;
	Unit(Vector2 position);
	~Unit();
	void Update() override;
};