#include "Window.h"

using namespace std;

Window::Window()
{

}

void Window::Init()
{
	if (!glfwInit())
		cout << "Failed to initialize GLFW" << endl;
	else
		cout << "GLFW initialized" << endl;	
	window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (window == NULL)
		cout << "Failed to create GLFW window" << endl;
	else
		cout << "Created GLFW window" << endl;
	glfwMakeContextCurrent(window);
	Exit = false;
}

void Window::PostRender()
{
	if (glfwWindowShouldClose(window))
		Exit = true;

	glfwSwapBuffers(window);
	glfwPollEvents();
}

Window::~Window()
{
	glfwTerminate();
}
