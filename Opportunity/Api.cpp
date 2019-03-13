#include "Api.h"
#include "Unit.h"

#define UNIT (static_cast<Unit*>(unit))//��������

Vector2 Engine::GetPosition(void* unit)
{
	return UNIT->position;
}

void Engine::SetDirection(void* unit, Vector2 direction)
{
	UNIT->SetDirection(direction);
}

Vector2 Engine::GetDirection(void* unit)
{
	return UNIT->GetDirection();
}

void Engine::SetSpeed(void* unit, float speed)
{
	UNIT->SetSpeed(speed);
}

float Engine::GetSpeed(void* unit)
{
	return UNIT->GetSpeed();
}