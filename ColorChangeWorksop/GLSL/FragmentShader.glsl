#version 460 core

out vec4 FragColor;

uniform vec4 UniformColor;

void main()
{
	FragColor = UniformColor;
}