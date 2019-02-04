#pragma once

#include <string>

#ifdef MANAGEDCPPLIBRARY_EXPORTS  
#define API __declspec(dllexport)
#else  
#define API __declspec(dllimport)   
#endif  

namespace ManagedCppLibrary
{
#ifdef CLI
	public
#endif
		class Compiler
	{
	public:
		static API void Compile(std::string text);
	};
}