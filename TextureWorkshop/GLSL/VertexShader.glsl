#version 460 core

layout (location = 0) in vec3 Pos;
layout (location = 1) in vec3 Color;
layout (location = 2) in vec2 TexCoordinates;

out vec3 UniColor;
out vec2 TexCoord;

void main()
{
	gl_Position = vec4(Pos, 1.0f);
	UniColor = Color;
	TexCoord = vec2(TexCoordinates.x, TexCoordinates.y);
}