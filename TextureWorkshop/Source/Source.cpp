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
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(sizeof(float) * 3));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(sizeof(float) * 6));
	glEnableVertexAttribArray(2);
}
void CreateTextures()
{
	glGenTextures(1, &Texture);
	glBindTexture(GL_TEXTURE_2D, Texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	unsigned char* data;

	data = stbi_load("./Textures/Wall.jpg", &width, &height, &nrChannels, 0);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_INT, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		printf("Failed to load texture!");
	}
	stbi_image_free(data);
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
	glfwSetFramebufferSizeCallback(MainWindow, FrameBufferSize);""

	//Check if GLAD has been initialized.
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("GLAD initialization has failed!");
		return 1;
	}

	//Declaring the Rendering Viewport to GLFW.
	

	//Initialize Shader.
	ShaderProgram* MainProgram = new ShaderProgram();

	//Attach Vertex and Fragment Shader.
	MainProgram->AttachShader("./GLSL/VertexShader.glsl", GL_VERTEX_SHADER);
	MainProgram->AttachShader("./GLSL/FragmentShader.glsl", GL_FRAGMENT_SHADER);

	//Link Shader.
	MainProgram->LinkProgram();

	//Create shader buffers.
	CreateBuffers();
	CreateTextures();

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

		glBindTexture(GL_TEXTURE_2D, Texture);

		//Use Program and bind Vertex Array Object.
		MainProgram->UseProgram();
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

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