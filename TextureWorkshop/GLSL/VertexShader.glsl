#version 460 core

layout (location = 0) in vec2 Pos;
layout (location = 1) in vec2 TexCoordinates;

out vec2 TexCoord;

void main()
{
	gl_Position = vec4(Pos, 0.0f, 1.0f);
	TexCoord = vec2(TexCoordinates.x, TexCoordinates.y);
}