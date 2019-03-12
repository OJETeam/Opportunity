#include "Time.h"

float Time::delta;
float Time::lastFrame;

float Time::DeltaTime()
{
	return delta;
}

void Time::Start()
{
	lastFrame = glfwGetTime();
}

void Time::Update()
{
	float currentFrame = glfwGetTime();
	delta = currentFrame - lastFrame;
	lastFrame = currentFrame;
}