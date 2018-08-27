#pragma once

#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <iostream>

class Window
{
private:
	const char* title = "Opportunity";
public:
	GLFWwindow* window;
	int width = 800;
	int height = 600; //TODO CHANGE THIS SHIT

	Window();
	void Init();
	void PostRender();
	bool Exit;
	~Window();
};

