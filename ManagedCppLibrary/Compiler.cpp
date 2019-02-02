#include "Compiler.h"
#include <msclr\marshal_cppstd.h>
#include <iostream>

using namespace System;
using namespace System::IO;
using namespace System::Reflection;
using namespace Microsoft::CSharp;
using namespace System::CodeDom::Compiler;
using std::cout;
using std::endl;

void ManagedCppLibrary::Compiler::Compile(std::string text)
{
	System::String^ clrStr = gcnew System::String(text.c_str());
	cout << msclr::interop::marshal_as<std::string>(clrStr) << endl;

	CSharpCodeProvider^ codeProvider = gcnew CSharpCodeProvider();

	CompilerParameters^ parameters = gcnew CompilerParameters();
	parameters->GenerateInMemory = true;
	parameters->GenerateExecutable = false;
	parameters->OutputAssembly = "CsScript";

	CompilerResults^ results = codeProvider->CompileAssemblyFromSource(parameters, clrStr);

	auto assemblies = AppDomain::CurrentDomain->GetAssemblies();

	for (int i = 0; i < assemblies->Length; i++)
	{
		cout << msclr::interop::marshal_as<std::string>(assemblies[i]->FullName) << endl;
	}
}