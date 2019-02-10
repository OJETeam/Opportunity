#include "Unit.h"
#include "Api.h"

Engine::Unit::Unit(void* unit) : unit(unit)
{
}

Engine::Vector2 Engine::Unit::GetPosition()
{
	return Api::GetPosition(unit);
}