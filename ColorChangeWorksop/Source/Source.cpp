#pragma region "Libraries"
// Regular Libraries
#include <stdio.h>

// OpenGL Window and Render Libraries
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Shader Libraries
#include "../Shader/ShaderProgram.h"

// Window Macros
#include "Source.h"

// Entity Libraries

#pragma endregion

#pragma region "Source Functions"
void FrameBufferSize(GLFWwindow* window, int Width, int Height)
{
	glViewport(0, 0, Width, Height);
}
void ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}
void CreateBuffers()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
	glEnableVertexAttribArray(0);
}
#pragma endregion

int main(int argumentCount, char** argumentValue)
{
	//Check if GLFW has been initialized.
	if (!glfwInit())
	{
		printf("GLFW has not been initialized.");
		return 1;
	}
	//Version selection OpenGL 4.6
	glfwInitHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwInitHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	//Core profile configuration
	glfwInitHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/*
	* The code below is needed if the code runs on Mac OSX.
	* glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	*/

	//Initilalize the window.
	GLFWwindow* MainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Triangle Window", NULL, NULL);

	//Check if window has been initialized.
	if (!MainWindow)
	{
		printf("Window initialization has failed!");
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(MainWindow);

	//Check if GLAD has been initialized.
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("GLAD initialization has failed!");
		return 1;
	}

	//Declaring the Rendering Viewport to GLFW.
	glfwSetFramebufferSizeCallback(MainWindow, FrameBufferSize);

	//Initialize Shader.
	ShaderProgram* MainProgram = new ShaderProgram();

	//Attach Vertex and Fragment Shader.
	MainProgram->AttachShader("./GLSL/VertexShader.glsl", GL_VERTEX_SHADER);
	MainProgram->AttachShader("./GLSL/FragmentShader.glsl", GL_FRAGMENT_SHADER);

	//Link Shader.
	MainProgram->LinkProgram();

	//Create shader buffers.
	CreateBuffers();

	while (!glfwWindowShouldClose(MainWindow))
	{
		/*
		* First process input, secondly refresh screen, then use shader in order to see the result.
		*/

		//Input function
		ProcessInput(MainWindow);

		//Clear the screen and print a color;
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		float Timer = glfwGetTime();
		float Color = ((sin(Timer) / 2.0f) + 0.5f);

		//Use Program and bind Vertex Array Object.
		MainProgram->UseProgram();
		MainProgram->Uniform(Color);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		/*
		* GL_FILL makes the Polygon Mode Normal but GL_LINE makes it wire.
		*/
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		//Continuously draw images and check for all inputs.
		glfwSwapBuffers(MainWindow);
		glfwPollEvents();
	}

	delete MainProgram;
	glfwTerminate();

	return 0;
}