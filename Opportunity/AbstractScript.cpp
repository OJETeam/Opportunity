#include "AbstractScript.h"
#include "CompilerApi.h"

int AbstractScript::scriptCount = 0;

AbstractScript::AbstractScript(const string& name, const string& text) : name(name), text(text)
{
	compiled = false;
	id = scriptCount;
	scriptCount++;
}

AbstractScript AbstractScript::FromFile(const string& name, const string& path)
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
	return AbstractScript(name, text);
}

bool AbstractScript::Compile()
{
	compiled = ScriptManager::CompilerApi::CompileScript(text); //TODO incapsulate
	return compiled;
}

void AbstractScript::RunScript(Unit* unit)
{
	ScriptManager::CompilerApi::RunScript(id, unit);
}