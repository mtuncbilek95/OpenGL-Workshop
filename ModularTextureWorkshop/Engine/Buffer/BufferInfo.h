#ifndef BUFFERINFO_H

#define BUFFERINFO_H

#include "../Core/Core.h"

enum class BufferUsage
{
	StaticDraw,
	DynamicDraw
};

enum class BufferType 
{
	ArrayObject,
	ArrayBuffer,
	ElementBuffer
};

enum class ObjectType
{
	ArrayObject,
	BufferObject
};

#endif	//! BUFFERINFO_H