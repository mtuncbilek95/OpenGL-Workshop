#pragma once
#version 460 core

out vec4 FragmentColor;

in vec3 UniformColor;
in vec2 TexCoord;

uniform sampler2D UniformTexture;

void main()
{
	FragmentColor = texture(UniformTexture, TexCoord);
}