#pragma once
#include "../Opportunity/Api.h"

using namespace System;

namespace Engine
{
	private ref class Api abstract sealed
	{
	public:
		static int GetPosition(void* unit);
	};
}