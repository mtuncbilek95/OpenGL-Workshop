#pragma once

#pragma region "Libraries"

//	Core Libraries
#include "../Engine/Core/Core.h"
#include "../Engine/Core/InputValues.h"

//	OpenGL Libraries
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//	Shader Libraries
#include "../Engine/Shader/Shader.h"

//	Buffer Libraries
#include "../Engine/Buffer/Buffer.h"

//	InputLayout Libraries

#pragma endregion

int main(int argC, char** argV)
{
	if (!glfwInit())
	{
		printf("Initialization has failed!");
		return 1;
	}

	glfwInitHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwInitHint(GLFW_CONTEXT_VERSION_MAJOR, 6);

	glfwInitHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* MainWindow = glfwCreateWindow(WIDTH, HEIGHT, WINDOWNAME, NULL, NULL);

	if (!MainWindow)
	{
		printf("Window initialization has failed!");
		return 1;
	}

	glfwMakeContextCurrent(MainWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("GLAD Initialization has failed!");
		glfwSetWindowShouldClose(MainWindow, true);
		return 1;
	}

	BufferBase* VertexBuffer = new BufferBase(Vertices, BufferType::ArrayBuffer);
	
	while (!glfwWindowShouldClose(MainWindow))
	{
		glfwSwapBuffers(MainWindow);
		glfwPollEvents();
	}

	return 0;
}