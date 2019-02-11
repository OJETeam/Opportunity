#pragma once
#include "../Api/Unit.h"
#include "IEventReceiver.h"

namespace Engine
{
	public ref class Script abstract : public IEventReceiver
	{
	internal:
		void* unit;
		void setUnit(void* unit);
	public:
		Unit^ Unit;
		Script();
	};
}