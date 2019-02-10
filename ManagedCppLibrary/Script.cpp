#include "Script.h"

Engine::Script::Script() : unit(nullptr)
{

}

void Engine::Script::setUnit(void* unit)
{
	this->unit = unit;
	Unit = gcnew Engine::Unit(unit);
}