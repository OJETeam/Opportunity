#include "Script.h"
#include "CompilerApi.h"

Script::Script(std::string text)
{
	this->text = text;
}

Script Script::FromFile(const string& path)
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
	return Script(text);
}

bool Script::Compile()
{
	return ScriptManager::CompilerApi::CompileScript(text); //TODO incapsulate
}

void Script::RunScript()
{
	ScriptManager::CompilerApi::RunScript(unit);
}

void Script::Update()
{
	ScriptManager::CompilerApi::Update();
}