#pragma once

#define STB_IMAGE_IMPLEMENTATION
#include "../Image Library/stb_image.h"

#define WIDTH 800
#define HEIGHT 800

unsigned int VBO, VAO, EBO;

unsigned int Textures;

float vertices[] = {
    // positions          // colors           // texture coords
     0.0f,  0.4f, 0.0f,   1.0f, 0.0f, 0.0f,   0.5f, 0.5f,   // top middle
     0.5f, -0.4f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
    -0.5f, -0.4f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
};

unsigned int indices[] = {
       0, 1, 3, // first triangle
       1, 2, 3  // second triangle
};