#include <iostream>

#include <glad\glad.h>
#include "Window.h"
#include "Game.h"

using namespace std;

int main()
{
	Window::Init();
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		cout << "Failed to initialize GLAD" << endl;
	else 
		cout << "GLAD initialized" << endl;

	while (!Window::Exit)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		Game::Update();
		Window::PostRender();
	}
	
	Window::Terminate();
}