#version 330 core
layout (location = 0) in vec2 aPos;
out vec4 Color;

uniform vec4 color;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	Color = color;
    gl_Position = projection * view * model * vec4(aPos.xy, 0.0f, 1.0f);
}