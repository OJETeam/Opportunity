#include <iostream>

#include <glad\glad.h>

#include "Window.h"

using namespace std;

int main()
{
	Window w;
	w.Init();

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		cout << "Failed to initialize GLAD" << endl;
	else 
		cout << "GLAD initialized" << endl;

	while (!w.Exit)
	{
		glClear(GL_COLOR_BUFFER_BIT);

		w.PostRender();
	}
	
	w.~Window();
}