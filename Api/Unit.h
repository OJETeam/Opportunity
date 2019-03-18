#pragma once
#include "Vector2.h"

namespace Engine
{
	public ref class Unit
	{
	private:
		void* unit;
	internal:
		Unit(void* unit);
	public:
		property float speed
		{
			float get();
			void set(float speed);
		}
		property Vector2 direction
		{
			Vector2 get();
			void set(Vector2 direction);
		}
		property float rotation
		{
			float get();
			void set(float direction);
		}
		Vector2 GetPosition();
	};
}