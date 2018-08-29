#include "Cube.h"

Cube::Cube(Vector2 position, float sideLength, Color color)
	: Object(position, Model({ Vector2(0, 0), Vector2(sideLength, 0), Vector2(0, sideLength), Vector2(0, sideLength), Vector2(sideLength, sideLength), Vector2(sideLength, 0) }, color))
{
	shader.Use();
	shader.SetMat4("view", Camera::ViewMatrix);
	shader.SetMat4("projection", Window::ProjectionMatrix);
	shader.Unbind();
}

void Cube::Render()
{
	glm::vec3 test = glm::vec3(position.x, position.y, 0);
	shader.Use();
	glm::mat4 mat4model = glm::mat4(1.0f);	
	mat4model = glm::translate(mat4model, test);
	shader.SetMat4("model", mat4model);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, model.model.size());
	shader.Unbind();
}

void Cube::Update()
{
}