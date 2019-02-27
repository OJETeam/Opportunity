#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

class Window
{
private:
	static const char* title;
public:
	static glm::mat4 ProjectionMatrix;
	static GLFWwindow* window;
	static int width;
	static int height;

	static void Init();
	static void Terminate();
	static void PostRender();
	static bool Exit;
};

