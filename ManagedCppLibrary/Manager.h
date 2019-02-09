#pragma once

#include <string>
#include <vector>
#include "Script.h"

using namespace System;
using namespace System::IO;
using namespace System::Reflection;
using namespace Microsoft::CSharp;
using namespace System::CodeDom::Compiler;
using namespace System::Collections::Generic;
using namespace Engine;

namespace ScriptManager
{
	private ref class Manager abstract sealed
	{
	internal:
		static List<CompiledScripts^> compilerScripts;
		static List<Script^> scripts;
		static bool CompileScript(String^ text);
		static void RunScript(void* unit);
		static void Update();
	};
}