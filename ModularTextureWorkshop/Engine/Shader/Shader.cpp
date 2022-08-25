#include "Shader.h"

ShaderProgram::ShaderProgram()
{
	ProgramId = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(ProgramId);
}

void ShaderProgram::AttachShader(const char* FileSource, const ShaderType Shader)
{
	uint32 ShaderHandle{};

	switch (Shader)
	{
	case ShaderType::VertexShader:
		ShaderHandle = glCreateShader(GL_VERTEX_SHADER);
		break;
	case ShaderType::FragmentShader:
		ShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
		break;
	}

	std::string Location = CatchFile(FileSource);
	const char* SourceCode = &Location[0];
	glShaderSource(ShaderHandle, 1, &SourceCode, NULL);

	int bIsCompiled;
	char log[512];

	glCompileShader(ProgramId);
	glGetShaderiv(ShaderHandle, GL_COMPILE_STATUS, &bIsCompiled);

	if (!bIsCompiled)
	{
		glGetShaderInfoLog(ShaderHandle, sizeof(log), 0, log);
		printf("Shader Compile Error: %s", log);
	}
}

void ShaderProgram::LinkProgram()
{
	glLinkProgram(ProgramId);

	int bIsLinked;
	char log[512];

	glGetShaderiv(ProgramId, GL_LINK_STATUS, &bIsLinked);
	if (!bIsLinked)
	{
		glGetShaderInfoLog(ProgramId, sizeof(log), 0, log);
		printf("Shader Link Error: %s", log);
	}
}

void ShaderProgram::UseProgram()
{
	glUseProgram(ProgramId);
}

std::string ShaderProgram::CatchFile(const char* FileName)
{
	std::ifstream file(FileName);

	std::string data;

	if (file.is_open())
	{
		char read;
		while ((read = file.get()) != EOF)
		{
			data += read;
		}
	}
	return data;
}