#include <iostream>

#include <glad\glad.h>
#include "Window.h"
#include "Game.h"
#include "Model.h"
#include "Object.h"

using namespace std;

int main()
{
	Window::Init();
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		cout << "Failed to initialize GLAD" << endl;
	else 
		cout << "GLAD initialized" << endl;

	glViewport(0, 0, Window::width, Window::height);
	glClearColor(1, 0, 1, 1);

	vector<Vector2> list;
	list.push_back(Vector2(0, 0));
	list.push_back(Vector2(1, 0));
	list.push_back(Vector2(1, 1));

	list.push_back(Vector2(1, 1));
	list.push_back(Vector2(0, 1));
	list.push_back(Vector2(0, 0));
	Model model(list);
	Object test(Vector2(0, 0), model);

	while (!Window::Exit)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		test.Render();
		Game::Update();
		Window::PostRender();
	}
	
	Window::Terminate();
}