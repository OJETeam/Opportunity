#include "Unit.h"

Unit::Unit(Vector2 position) : Object(position, Model(vector<Vector2>(), Color::Red))
{
}

Unit::~Unit()
{
}

void Unit::Update()
{
}

int Unit::GetPosition(void* unit)
{
	cout << "OMG IT WORKED" << endl;
	return 55;
	//return ((Unit*)unit)->position;
}