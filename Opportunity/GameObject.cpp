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

	shader.SetVec4("color", model.color.r, model.color.g, model.color.b, model.color.a); //TODO optimize, remove all getuniformlocation calls
	shader.SetMat4("model", modelMatrix);
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