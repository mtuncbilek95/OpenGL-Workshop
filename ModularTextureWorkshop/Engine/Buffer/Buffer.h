#ifndef  BUFFER_H

#define BUFFER_H

#include <glad/glad.h>
#include "BufferInfo.h"


class BufferBase
{
public:
	BufferBase(const void* InputData, BufferType BufferType);
	~BufferBase() = default;

	void UnbindBuffer();
	void CreateBuffer(BufferUsage BufferDrawType);
	void GenerateBuffer(uint Count);
	void BindBuffer();
private:
	uint BufferId;
	
	const void* BufferData;
	
	BufferType BufferHandle;
	BufferUsage BufferDrawHandle;
};

#endif //	!BUFFER_H