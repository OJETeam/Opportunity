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
	internal:
		static Engine::Vector2 GetPosition(void* unit);
	};
}