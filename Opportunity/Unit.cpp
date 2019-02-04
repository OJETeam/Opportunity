#include "Unit.h"

Unit::Unit(Vector2 position) : Object(position, Model(vector<Vector2>(), Color::Red))
{
}

Unit::~Unit()
{
}