#pragma once
#include "Script.h"

using namespace System;
using namespace System::Reflection;

namespace ScriptManager
{
	ref class CompiledScript
	{
	private:
		Assembly^ assembly;
		Type^ scriptType;
	public:
		CompiledScript(Type^ scriptType, Assembly^ assembly);
		Engine::Script^ CreateScript(void* unit);
	};
}