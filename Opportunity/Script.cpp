#include "Script.h"
#include "CompilerApi.h"

int Script::scriptCount = 0;

Script::Script(const string& name, const string& text) : name(name), text(text)
{
	id = scriptCount;
	scriptCount++;
}

Script Script::FromFile(const string& name, const string& path)
{
	ifstream file(path);
	if (!file.is_open())
		throw exception();

	file.seekg(0, ios::end);
	int length = (int)file.tellg() + 1;
	file.seekg(0, ios::beg);
	char* buff = new char[length]();
	file.read(buff, length);
	buff[length - 1] = 0;
	string text(buff);
	delete[] buff;
	return Script(name, text);
}

bool Script::Compile()
{
	return ScriptManager::CompilerApi::CompileScript(text); //TODO incapsulate
}

void Script::RunScript(Unit* unit)
{
	ScriptManager::CompilerApi::RunScript(id, unit);
}

void Script::Update()
{
	ScriptManager::CompilerApi::Update();
}