#include <msclr/marshal_cppstd.h>
#include <iostream>
#include "Compiler.h"

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

	CSharpCodeProvider^ codeProvider = gcnew CSharpCodeProvider();

	CompilerParameters^ parameters = gcnew CompilerParameters();
	parameters->GenerateInMemory = true;
	parameters->GenerateExecutable = false;
	parameters->CompilerOptions += "/unsafe";
	parameters->OutputAssembly = "CsScript";
	parameters->ReferencedAssemblies->Add("System.dll");
	parameters->ReferencedAssemblies->Add("System.Core.dll");
	parameters->ReferencedAssemblies->Add("ManagedCppLibrary.dll");
	
	Console::WriteLine("Referenced assemblies:");
	for each(String^ error in parameters->ReferencedAssemblies)
	{
		Console::WriteLine(error);
	}
	
	CompilerResults^ results = codeProvider->CompileAssemblyFromSource(parameters, clrStr);
	Console::WriteLine("Errors:");
	for each(CompilerError^ error in results->Errors)
	{
		Console::WriteLine(error->ErrorText + "\n");
	}

	System::Collections::Generic::List<int>^ list = gcnew System::Collections::Generic::List<int>();
	int i = System::Linq::Enumerable::FirstOrDefault(list);

	results->CompiledAssembly->GetType("Fuck.Test")->GetMethod("TestFunc")->Invoke(nullptr, nullptr);

	/*for each(auto str in results->CompiledAssembly->GetTypes())
	{
		Console::WriteLine(str);
	}

	auto assemblies = AppDomain::CurrentDomain->GetAssemblies();

	for (int i = 0; i < assemblies->Length; i++)
	{
		cout << msclr::interop::marshal_as<std::string>(assemblies[i]->FullName) << endl;
	}*/
}