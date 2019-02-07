#pragma once
#include "Vector2.h"

using namespace ManagedCppLibrary;

namespace ManagedCppLibrary
{
	class Api
	{
	public:
		static __declspec(dllimport) int GetPosition(void* unit);
	};

	public ref class Test abstract sealed
	{
	public:
		static int GetPosition(void* unit) { return Api::GetPosition(unit); }
	};
}