#pragma once
#include <string>
#include <fstream>
#include <sstream>

class Unit;
using namespace std;

class AbstractScript
{
private:
	bool compiled;
	int id; //TODO Manage ids!
	static int scriptCount;
public:
	string name;
	string text;
	AbstractScript(const string& name, const string& text);
	static AbstractScript FromFile(const string& name, const string& path);
	bool Compile(); //TODO return not bool, but CompilationResult
	void RunScript(Unit* unit);
};