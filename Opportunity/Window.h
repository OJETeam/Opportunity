#pragma once

#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <iostream>

class Window
{
private:
	static const char* title;
public:
	static GLFWwindow* window;
	static int width;
	static int height;

	static void Init();
	static void Terminate();
	static void PostRender();
	static bool Exit;
};

