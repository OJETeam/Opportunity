#pragma once
#include "../Api/Unit.h"

using namespace System;
using namespace System::Reflection;
using namespace ScriptManager;

namespace Engine
{
	public ref class Script abstract : public ScriptManager::IEventReceiver
	{
	public:
		void* unit;
		ScriptManager::IEventReceiver^ create(void* unit);
	public:
		Unit^ Unit;
		Script();
		virtual void Start() = 0;
		virtual void Update() = 0;
	};
}