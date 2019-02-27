#include "Api.h"
#include "Unit.h"

Vector2 Engine::GetPosition(void* unit)
{
	return static_cast<Unit*>(unit)->position;
}