#pragma once
#include "../Opportunity/Api.h"
#include "Vector2.h"

using namespace System;
using namespace Engine;

namespace Engine
{
	private ref class Api abstract sealed
	{
	private:
		static Engine::Vector2 ConvertVector(::Vector2 vec);
	internal:
		static Engine::Vector2 GetPosition(void* unit);
	};
}