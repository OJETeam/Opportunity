#include "Api.h"

Engine::Vector2 Api::GetPosition(void* unit)
{
	return ConvertVector(Engine::GetPosition(unit));
}

Engine::Vector2 Api::ConvertVector(::Vector2 vec)
{
	return Engine::Vector2(vec.x, vec.y);
}