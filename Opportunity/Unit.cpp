#include "Unit.h"

Unit::Unit(Vector2 position) : Object(position, Model(vector<Vector2>(), Color::Red))
{
}

Unit::~Unit()
{
}

void Unit::AttachScript(AbstractScript* script, bool run)
{
	Script currentScript(script, this);
	scripts.push_back(currentScript);

	if (run)
		currentScript.Start();
}

void Unit::Update()
{

}