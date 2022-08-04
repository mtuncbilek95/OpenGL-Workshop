#include "Shader.h"

ShaderProgram::ShaderProgram()
{

}

ShaderProgram::~ShaderProgram()
{

}

void ShaderProgram::AttachShader(const char* FileSource,const ShaderType Shader)
{
	uint32 ShaderType{};

	switch (Shader)
	{
	case ShaderType::VertexShader:
		ShaderType = glCreateShader(GL_VERTEX_SHADER);
		break;
	case ShaderType::FragmentShader:
		ShaderType = glCreateShader(GL_FRAGMENT_SHADER);
		break;
	}

	std::string Location = CatchFile(FileSource);
	const char* SourceCode = &Location[0];
	glShaderSource(ShaderType, 1, &SourceCode, NULL);

	int bIsCompiled;
	char log[512];

	glCompileShader(ProgramId);
	glGetShaderiv(ShaderType, GL_COMPILE_STATUS, &bIsCompiled);
	if (!bIsCompiled)
	{
		glGetShaderInfoLog(ShaderType, sizeof(log), 0, log);
		printf("Shader Initialization Error: %s", log);
	}
}

void ShaderProgram::LinkProgram()
{
	glLinkProgram(ProgramId);
}

void ShaderProgram::UseProgram()
{

}

std::string ShaderProgram::CatchFile(const char* FileName)
{

}