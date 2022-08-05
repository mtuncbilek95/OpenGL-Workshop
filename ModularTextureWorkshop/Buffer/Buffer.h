#ifndef  BUFFER_H

#define BUFFER_H

#include "BufferInfo.h"

#include <glad/glad.h>

class BufferBase
{
public:
	BufferBase();
	~BufferBase();

	void CreateBuffer();

private:
	BufferData Data;
	

	void OffsetCalculation();
};

#endif //	!BUFFER_H