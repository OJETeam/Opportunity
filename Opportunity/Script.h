#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include "Unit.h"

using namespace std;

class Unit;

class Script
{
private:
	Unit* unit;
public:
	string text;
	Script(string path);
	static Script FromFile(const string& path);
	bool Compile(); //TODO return not bool, but CompilationResult
	void RunScript();
	void Update();
};