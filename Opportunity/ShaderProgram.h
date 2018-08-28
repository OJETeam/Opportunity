#pragma once

#include <glad/glad.h>
#include <iostream>
#include <string>
#include <fstream>
#include <GLFW/glfw3.h>
#include <sstream>
#include <glm/glm.hpp>

class ShaderProgram
{
private:
	unsigned int object = 0;
public:
	ShaderProgram(std::string vertex, std::string fragment, std::string geometry);
	void Use();
	void Unbind();
	void SetMat4(const std::string &name, const glm::mat4 &mat);
};

