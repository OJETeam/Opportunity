#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "GameObject.h"
#include "Camera.h"
#include "Window.h"
#include "PivotVisualizer.h"
#include "Game.h"

GameObject::GameObject(Vector2 position, Model model) : Object(position, model)
{
}

void GameObject::Render()
{
	shader.Use();

	glm::mat4 mat4model = glm::mat4(1.0f);
	mat4model = glm::translate(mat4model, glm::vec3(position.x, position.y, 0));
	mat4model = glm::scale(mat4model, glm::vec3(size.x, size.y, 1.0f));
	if (parent)
	{
		glm::vec3 pos = glm::vec3(position.x - parent->getPosition().x, position.y - parent->getPosition().y, 0);
		mat4model = glm::translate(mat4model, -pos);
		mat4model = glm::rotate(mat4model, parent->getRotation(), glm::vec3(0, 0, 1));
		mat4model = glm::translate(mat4model, pos);
	}
	mat4model = glm::rotate(mat4model, rotation, glm::vec3(0, 0, 1));
	mat4model = glm::translate(mat4model, glm::vec3(-model.pivot.x, -model.pivot.y, 0));

	shader.SetVec4("color", model.color.r, model.color.g, model.color.b, model.color.a); //TODO optimize, remove all getuniformlocation calls
	shader.SetMat4("model", mat4model);
	shader.SetMat4("view", Camera::viewMatrix);
	shader.SetMat4("projection", Window::projectionMatrix);

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, model.model.size());

	shader.Unbind();
}

void GameObject::SetParent(GameObject& parent, bool reposition)
{
	if (reposition)
		setPosition(parent.getPosition());

	parent.children.push_back(this);
	this->parent = &parent;
}

GameObject* GameObject::GetParent() const
{
	return reinterpret_cast<GameObject*>(parent);
}