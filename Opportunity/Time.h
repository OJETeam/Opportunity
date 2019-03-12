#pragma once
#include <GLFW\glfw3.h>

class Time
{
private:
	static float delta;
	static float lastFrame;
public:
	static float DeltaTime();
	static void Start();
	static void Update();
};