#pragma once

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

enum class VertexInputDataType
{
	Float1,
	Float2,
	Float3,
	Float4
};

enum class ObjectType
{
	ArrayObject,
	BufferObject
};