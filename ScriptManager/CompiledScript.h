#pragma once
#include "IEventReceiver.h"

using namespace System;
using namespace System::Reflection;

namespace ScriptManager
{
	public ref class CompiledScript
	{
	internal:
		delegate ScriptManager::IEventReceiver^ Create(void* unit);
		static MethodInfo^ methodCreate;
		Assembly^ assembly;
		Type^ scriptType;
	public:
		CompiledScript(Type^ scriptType, Assembly^ assembly);
		IEventReceiver^ CreateScript(void* unit);
	};
}