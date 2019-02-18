#pragma once

#include <string>
#include <vector>
#include "CompiledScript.h"
#include "IEventReceiver.h"

using namespace System;
using namespace System::IO;
using namespace System::Reflection;
using namespace Microsoft::CSharp;
using namespace System::CodeDom::Compiler;
using namespace System::Collections::Generic;

namespace ScriptManager
{
	private ref class Manager abstract sealed
	{
	internal:
		static Type^ scriptType;
		static List<CompiledScript^> compiledScripts;
		static List<IEventReceiver^> scripts;
		static bool CompileScript(String^ text);
		static void RunScript(int id, void* unit);
		static void Update();
	};
}