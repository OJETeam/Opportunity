#include "Object.h"
#include "Window.h"
#include "Camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Object::Object(Vector2 position, Model model) : model(model), position(position), shader("vertex.txt", "fragment.txt", "")
{
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	UpdateModel();

	shader.Use();
	shader.SetMat4("view", Camera::ViewMatrix);
	shader.SetMat4("projection", Window::ProjectionMatrix);
	shader.Unbind();
}

void Object::Render()
{
	shader.Use();
	shader.SetVec4("color", model.color.r, model.color.g, model.color.b, model.color.a); //TODO optimize, remove all getuniformlocation calls
	glm::mat4 mat4model = glm::mat4(1.0f);
	mat4model = glm::translate(mat4model, glm::vec3(position.x, position.y, 0));
	mat4model = glm::scale(mat4model, glm::vec3(scale.x, scale.y, 1.0f));
	mat4model = glm::rotate(mat4model, rotation, glm::vec3(0, 0, 1));
	shader.SetMat4("model", mat4model);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, model.model.size());
	shader.Unbind();
}

void Object::UpdateModel()
{
	if (model.model.empty())
		return;

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vector2), nullptr);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vector2) * model.model.size(), model.model.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Object::OnCreate()
{
}

void Object::OnDelete()
{
}