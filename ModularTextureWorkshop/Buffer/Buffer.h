#ifndef  BUFFER_H

#define BUFFER_H

#include <glad/glad.h>
#include "BufferInfo.h"


class BufferBase
{
public:
	BufferBase(BufferType BufferType, BufferUsage BufferDrawType);
	~BufferBase() = default;

	void UnbindBuffer();
	void CreateBuffer();
	void GenerateBuffer(uint Count);
	void BindBuffer();
private:
	uint BufferId;
	BufferType BufferHandle;
	BufferUsage BufferDrawHandle;
};

#endif //	!BUFFER_H