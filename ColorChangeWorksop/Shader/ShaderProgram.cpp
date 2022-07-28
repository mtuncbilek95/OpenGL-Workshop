#include "ShaderProgram.h"

ShaderProgram::ShaderProgram()
{
	ProgramId = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(ProgramId);
}

void ShaderProgram::AttachShader(const char* FileName, unsigned int ShaderType)
{
	unsigned int ShaderId = glCreateShader(ShaderType);

	std::string Location = CatchFile(FileName);
	const char* SourceCode = &Location[0];

	glShaderSource(ShaderId, 1, &SourceCode, NULL);

	int bIsCompiled;
	char log[512];

	glCompileShader(ShaderId);
	glGetShaderiv(ShaderId, GL_COMPILE_STATUS, &bIsCompiled);

	if (!bIsCompiled)
	{
		glGetShaderInfoLog(ShaderId, sizeof(log), 0, log);
		printf("Compile Error: %d, %s", ShaderId, log);
	}

	glAttachShader(ProgramId, ShaderId);
}

void ShaderProgram::LinkProgram()
{
	glLinkProgram(ProgramId);

	int bIsCompiled;
	char log[512];

	glGetShaderiv(ProgramId, GL_LINK_STATUS, &bIsCompiled);
	if (!bIsCompiled)
	{
		glGetShaderInfoLog(ProgramId, sizeof(log), 0, log);
		printf("Link Error: %d \n %s", ProgramId, log);
	}
}

void ShaderProgram::UseProgram()
{
	glUseProgram(ProgramId);
}

int ShaderProgram::ColorLocation()
{
	return glGetUniformLocation(ProgramId, "UniformColor");
}

void ShaderProgram::Uniform(float value)
{
	glUniform4f(ColorLocation(), 0.0f, value, 0.0f, 1.0f);
}

std::string ShaderProgram::CatchFile(const char* FileName)
{
	std::ifstream file(FileName);
	std::string data;

	if (file.is_open())
	{
		char addData;
		while ((addData = file.get()) != EOF)
		{
			data += addData;
		}
	}
	return data;
}
