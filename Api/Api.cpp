#include "Api.h"

Engine::Vector2 Api::GetPosition(void* unit)
{
	return Vector2(Engine::GetPosition(unit));
}