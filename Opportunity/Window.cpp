#include "Window.h"

using namespace std;

const char* Window::title = "Opportunity";

int Window::width = 800;
int Window::height = 600;
bool Window::Exit = false;
GLFWwindow* Window::window;

void Window::Init()
{
	if (!glfwInit())
		cout << "Failed to initialize GLFW" << endl;
	else
		cout << "GLFW initialized" << endl;	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (window == NULL)
		cout << "Failed to create GLFW window" << endl;
	else
		cout << "Created GLFW window" << endl;
	glfwMakeContextCurrent(window);
}

void Window::Terminate()
{
	glfwTerminate();
}

void Window::PostRender()
{
	if (glfwWindowShouldClose(window))
		Exit = true;

	glfwSwapBuffers(window);
	glfwPollEvents();
}
