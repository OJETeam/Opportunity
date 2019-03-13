#pragma once

#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Vector2.h"

class ShaderProgram
{
private:
	unsigned int object = 0;
public:
	ShaderProgram(std::string vertex, std::string fragment, std::string geometry);
	void Use();
	void Unbind();
	void SetMat4(const char *name, const glm::mat4 &mat);
	void SetVec1(const char *name, const float vec0);
	void SetVec2(const char *name, Vector2 vec);
	void SetVec4(const char *name, float vec0, float vec1, float vec2, float vec3);
	int GetProgram();
};
