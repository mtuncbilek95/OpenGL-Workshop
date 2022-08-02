#pragma once

#define STB_IMAGE_IMPLEMENTATION
#include "../Image Library/stb_image.h"

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

#define WIDTH 800
#define HEIGHT 800

unsigned int VBO, VAO, EBO;
unsigned int Texture;

struct VertexData
{
	glm::vec3 Pos;
	glm::vec3 Color;
	glm::vec2 TexCoord; 
};

VertexData Vertices[] = {
	{{ 0.5f,  0.5f, 0.0f},	{1.0f, 0.0f, 0.0f},	{1.0f, 1.0f}},
	{{ 0.5f, -0.5f, 0.0f},	{0.0f, 1.0f, 0.0f},	{1.0f, 0.0f}},
	{{-0.5f, -0.5f, 0.0f},	{0.0f, 0.0f, 1.0f},	{0.0f, 0.0f}},
	{{-0.5f,  0.5f, 0.0f},	{1.0f, 1.0f, 0.0f},	{0.0f, 1.0f}},
};

unsigned int Indices[] = {
	   0, 1, 3, // first triangle
	   1, 2, 3  // second triangle
};



