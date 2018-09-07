#include "Main.h"

using namespace System::IO;

void Main::Compile()
{
	TextWriter^ t = gcnew StreamWriter("fuck.txt");
	t->WriteLine("WTF IS THIS");
}