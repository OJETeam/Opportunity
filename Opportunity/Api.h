#pragma once

#ifdef ENGINE_API
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif

namespace Api
{
	API void Run();
	API int GetPosition(void* unit);
}