#pragma once
#include "../Api/Unit.h"

namespace Engine
{
	public ref class Script abstract
	{
	internal:
		void* unit;
		void setUnit(void* unit);
	public:
		Unit^ Unit //SHOULD NOT BE HERE
		Script();
		virtual void Start() = 0;
		virtual void Update() = 0;
	};
}