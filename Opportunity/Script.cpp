#include "Script.h"
#include "Compiler.h"

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
	ManagedCppLibrary::Compiler::Compile(text); //TODO incapsulate
	return true;
}