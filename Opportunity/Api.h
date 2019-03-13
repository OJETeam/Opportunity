#pragma once
#include "../Opportunity/Vector2.h"

#ifdef ENGINE_API
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif

namespace Engine
{
	API ::Vector2 GetPosition(void* unit);
	API void SetDirection(void* unit, ::Vector2 direction);
	API ::Vector2 GetDirection(void* unit);
	API void SetSpeed(void* unit, float speed);
	API float GetSpeed(void* unit);
}