#pragma once
#include <string>

#ifdef CLI
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif

namespace ScriptManager
{
	class CompilerApi
	{
	public:
		static API bool CompileScript(std::string text);
		static API void RunScript(void* unit);
		static API void Update();
	};
}