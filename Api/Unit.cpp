#include "Unit.h"
#include "../Opportunity/Api.h"

Engine::Unit::Unit(void* unit) : unit(unit)
{
}

float Engine::Unit::speed::get()
{
	return GetSpeed(unit);
}

void Engine::Unit::speed::set(float speed)
{
	SetSpeed(unit, speed);
}

Engine::Vector2 Engine::Unit::direction::get()
{
	return Vector2(GetDirection(unit));
}

void Engine::Unit::direction::set(Vector2 direction)
{
	SetDirection(unit, direction);
}

Engine::Vector2 Engine::Unit::GetPosition()
{
	return Vector2(Engine::GetPosition(unit));
}
