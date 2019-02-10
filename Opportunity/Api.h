#pragma once
#include "Vector2.h"

#ifdef ENGINE_API
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif

namespace Engine
{
	API void Run();
	API Vector2 GetPosition(void* unit);
}