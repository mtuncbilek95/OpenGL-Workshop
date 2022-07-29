#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#pragma region "Libraries"
// Regular Libraries
#include <string>
#include <fstream>

// OpenGL Libraries
#include <glad/glad.h>
#pragma endregion

/*
*  This class is used for handling all the shader works.
*/
class ShaderProgram
{
public:
	ShaderProgram();
	~ShaderProgram();
	
	void AttachShader(const char* FileName, unsigned int ShaderType);
	void LinkProgram();
	void UseProgram();
private:

	// This is a function for transfering the glsl data to Shader.
	std::string CatchFile(const char* FileName);
	unsigned int ProgramId{};
};

#endif