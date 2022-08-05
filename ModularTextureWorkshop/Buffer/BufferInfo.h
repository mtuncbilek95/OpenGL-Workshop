#pragma once

#include "../Core/Core.h"

enum class BufferUsage
{
	StaticDraw,
	DynamicDraw
};

enum class BufferType 
{
	ArrayBuffer,
	ElementBuffer
};

enum class VertexInputDataType
{
	Float0,
	Float1,
	Float2,
	Float3
};

struct BufferData
{
	uint32	VertexArrayObject;
	uint32	VertexBufferObject;
	uint32	ElementBufferObject;
};