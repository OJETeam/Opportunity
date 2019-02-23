#include "Unit.h"

Unit::Unit(Vector2 position) : Object(position, Model(vector<Vector2>(), Color::Red))
{
}

Unit::~Unit()
{
}

void Unit::Update()
{
	for (Script* script : scripts)
	{
		script->Update();
	}
}