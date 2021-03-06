#include <fstream>
#include <sstream>
#include <glad/glad.h>
#include <iostream>
#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(std::string vertex = "vertex.txt", std::string fragment = "fragment.txt", std::string geometry = "")
{
	object = glCreateProgram();
	int shader = glCreateShader(GL_VERTEX_SHADER);
	std::ifstream file(vertex);
	if (!file.is_open())
		std::cout << "No such file : " << vertex << std::endl;
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string str = buffer.str();
	char const* vertexSourcePointer = str.c_str();
	glShaderSource(shader, 1, &vertexSourcePointer, NULL);
	glCompileShader(shader);
	glAttachShader(object, shader);
	glDeleteShader(shader);
	char* arr = new char[512];
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, arr);
		std::cout << "Vertex shader : " << arr << std::endl;
	}
	delete[] arr;

	shader = glCreateShader(GL_FRAGMENT_SHADER);
	file.open(fragment);
	if (!file.is_open())
		std::cout << "No such file : " << fragment << std::endl;
	buffer.str("");
	buffer << file.rdbuf();
	file.close();
	str = buffer.str();
	const char* fragmentSourcePointer = str.c_str();
	glShaderSource(shader, 1, &fragmentSourcePointer, NULL);
	glCompileShader(shader);
	glAttachShader(object, shader);
	glDeleteShader(shader);
	arr = new char[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, arr);
		std::cout << "Fragment shader : " << arr << std::endl;
	}
	delete[] arr;

	if (geometry != "")
	{
		shader = glCreateShader(GL_GEOMETRY_SHADER);
		file.open(geometry);
		if (!file.is_open())
			std::cout << "No such file : " << geometry << std::endl;
		buffer.str("");
		buffer << file.rdbuf();
		file.close();
		str = buffer.str();
		char const* geometrySourcePointer = str.c_str();
		glShaderSource(shader, 1, &geometrySourcePointer, NULL);
		glCompileShader(shader);
		glAttachShader(object, shader);
		glDeleteShader(shader);
		arr = new char[512];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, arr);
			std::cout << "Useless shader : " << arr << std::endl;
		}
		delete[] arr;
	}
	glLinkProgram(object);
	Unbind();
}

void ShaderProgram::SetMat4(const char *name, const glm::mat4 &mat)
{
	glUniformMatrix4fv(glGetUniformLocation(object, name), 1, GL_FALSE, glm::value_ptr(mat));
}

void ShaderProgram::SetVec1(const char* name, const float vec0)
{
	glUniform1f(glGetUniformLocation(object, name), vec0);
}

void ShaderProgram::SetVec2(const char* name, Vector2 vec)
{
	glUniform2f(glGetUniformLocation(object, name), vec.x, vec.y);
}

void ShaderProgram::SetVec4(const char* name, float vec0, float vec1, float vec2, float vec3)
{
	glUniform4f(glGetUniformLocation(object, name), vec0, vec1, vec2, vec3);
}

int ShaderProgram::GetProgram()
{
	return object;
}

void ShaderProgram::Use()
{
	glUseProgram(object);
}

void ShaderProgram::Unbind()
{
	glUseProgram(0);
}
