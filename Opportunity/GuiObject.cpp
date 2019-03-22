#include "GuiObject.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Camera.h"
#include "Window.h"

GuiObject::GuiObject(Vector2 position, Model model) : Object(position, model)
{

}

void GuiObject::Render()
{
	shader.Use();
	shader.SetVec4("color", model.color.r, model.color.g, model.color.b, model.color.a); //TODO optimize, remove all getuniformlocation calls
	glm::mat4 mat4model = glm::mat4(1.0f);
	mat4model = glm::translate(mat4model, glm::vec3(position.x, position.y, 0));
	mat4model = glm::scale(mat4model, glm::vec3(scale.x, scale.y, 1.0f));
	mat4model = glm::rotate(mat4model, rotation, glm::vec3(0, 0, 1));
	mat4model = glm::translate(mat4model, glm::vec3(-model.pivot.x, -model.pivot.y, 0));
	shader.SetMat4("model", mat4model);
	shader.SetMat4("projection", Window::projectionMatrix);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, model.model.size());
	shader.Unbind();
}

void GuiObject::SubscribeClick(ClickEvent response)
{
	events.push_back(response);
}

void GuiObject::UnsubscribeClick(ClickEvent response)
{
	for (auto i = events.begin(); i != events.end(); ++i)
	{
		if (*i == response)
		{
			events.erase(i);
			return;
		}
	}
}