#ifndef SHADER_H

#define SHADER_H

#include "ShaderInfo.h"

class ShaderProgram
{
public:
	ShaderProgram();
	~ShaderProgram();

	void AttachShader(const char* FileSource, const ShaderHandle Shader);
	void LinkProgram();
	void UseProgram();

protected:

	uint32 ProgramId{};
	std::string CatchFile(const char* FileName);
};


#endif //	!SHADER_H

