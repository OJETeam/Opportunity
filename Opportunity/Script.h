#pragma once
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Script
{
public:
	string text;
	Script(string path);
	static Script FromFile(const string& path);
	bool Compile(); //TODO return not bool, but CompilationResult
};