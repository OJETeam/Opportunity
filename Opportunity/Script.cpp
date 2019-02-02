#include "Script.h"
#include "Compiler.h"

Script::Script(std::string text)
{
	this->text = text;
}

Script Script::FromFile(const string& path)
{
	ifstream file(path);
	file.seekg(ios::end, 0);
	int length = file.tellg();
	file.seekg(ios::beg, 0);
	char* buff = new char[length];
	file.read(buff, length);
	string text(buff);
	delete[] buff;
	return Script(text);
}

bool Script::Compile()
{
	ManagedCppLibrary::Compiler::Compile(text); //TODO incapsulate
	return true;
}