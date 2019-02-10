#pragma once
#include "Vector2.h"

using namespace Engine;

namespace Engine
{
	public ref class Unit
	{
	private:
		void* unit;
	internal:
		Unit(void* unit);
	public:
		Vector2 GetPosition();
	};
}
