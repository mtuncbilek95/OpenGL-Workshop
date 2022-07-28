#pragma once

#define WIDTH 800
#define HEIGHT 800

unsigned int VBO, VAO;

float vertices[] = {
    // positions         // colors
     0.5f, -0.4f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
    -0.5f, -0.4f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
     0.0f,  0.4f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
};