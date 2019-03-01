#include <msclr/marshal_cppstd.h>
#include <iostream>
#include "Manager.h"

bool ScriptManager::Manager::CompileScript(String^ text) //TODO accept script ID as parameter
{
	CSharpCodeProvider^ codeProvider = gcnew CSharpCodeProvider();

	CompilerParameters^ parameters = gcnew CompilerParameters();
	parameters->GenerateInMemory = true;
	parameters->GenerateExecutable = false;
	parameters->CompilerOptions += "/unsafe";
	parameters->ReferencedAssemblies->Add("System.dll");
	parameters->ReferencedAssemblies->Add("System.Xml.dll");
	parameters->ReferencedAssemblies->Add("System.Data.dll");
	parameters->ReferencedAssemblies->Add("System.Core.dll");
	parameters->ReferencedAssemblies->Add("Api.dll");
	parameters->ReferencedAssemblies->Add("ScriptManager.dll");
	Console::WriteLine("Referenced assemblies:");
	for each(String^ error in parameters->ReferencedAssemblies)
	{
		Console::WriteLine(error);
	}

	CompilerResults^ results = codeProvider->CompileAssemblyFromSource(parameters, text);
	Console::WriteLine("Errors:");
	for each(CompilerError^ error in results->Errors)
	{
		Console::WriteLine(error->ErrorText + "\n");
	}

	Type^ foundType = nullptr;

	Assembly^ compiledAssembly = results->CompiledAssembly;

	for each(Type^ type in compiledAssembly->GetTypes())
	{
		if (type->BaseType->FullName != "Engine.Script")
			continue;

		if (foundType)
			return false; //ensure that one file contains only one Script
		foundType = type;
	}
	compiledScripts.Add(gcnew CompiledScript(foundType, results->CompiledAssembly));

	Console::WriteLine("Assembly name:");
	Console::WriteLine(compiledAssembly->FullName);

	return true;
}

void ScriptManager::Manager::RunScript(int id, void* unit)
{
	IEventReceiver^ script = compiledScripts[id]->CreateScript(unit);
	scripts.Add(script);
	script->Start();
}

void ScriptManager::Manager::Update()
{
	for each(IEventReceiver^ script in scripts)
	{
		script->Update();
	}
}