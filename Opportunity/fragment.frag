#version 330 core

out vec4 color;

in vec4 Color;

void main()
{
	//if(gl_FragCoord.x < 400)
	//	color = Color * 0.2;
	//else
		color = Color;
}