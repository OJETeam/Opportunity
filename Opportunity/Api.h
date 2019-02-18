#pragma once
#include "../Opportunity/Vector2.h"

#ifdef ENGINE_API
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif

namespace Engine
{
	API Vector2 GetPosition(void* unit);
}