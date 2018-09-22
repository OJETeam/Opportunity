#include "Compiler.h"

using namespace System;
using namespace System::IO;
using namespace System::Reflection;
using namespace Microsoft::CSharp;
using namespace System::CodeDom::Compiler;

void ManagedCppLibrary::Compiler::Compile(std::string text)
{
	System::String^ clrStr = gcnew System::String(text.c_str());
	TextWriter^ t = gcnew StreamWriter("fuck.txt");
	t->WriteLine("WTF IS THIS");
	t->Write(clrStr);

	CSharpCodeProvider^ codeProvider = gcnew CSharpCodeProvider();

	CompilerParameters^ parameters = gcnew CompilerParameters();
	parameters->GenerateInMemory = true;
	parameters->GenerateExecutable = false;
	parameters->OutputAssembly = "CsScript";

	CompilerResults^ results = codeProvider->CompileAssemblyFromSource(parameters, clrStr);

	auto assemblies = AppDomain::CurrentDomain->GetAssemblies();

	for(int i = 0; i < assemblies->Length; i++)
	{
		t->WriteLine(assemblies[i]->FullName);
	}

	t->Close();`
}