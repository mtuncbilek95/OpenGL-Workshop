#include "Buffer.h"

BufferBase::BufferBase(const void* InputData, BufferType BufferType)
{
	BufferHandle = BufferType;
	BufferData = InputData;
}

void BufferBase::UnbindBuffer()
{
	switch (BufferHandle)
	{
		// TODO: Array Object buradan çıkar standalone class yap.
	case BufferType::ArrayObject:
		glBindVertexArray(0);
		break;
	case BufferType::ArrayBuffer:
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		break;
	case BufferType::ElementBuffer:
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		break;
	default:
		break;
	}
}

void BufferBase::CreateBuffer(BufferUsage BufferDrawType)
{
	uint BufferType = 0;
	uint DrawType = 0;
	switch (BufferHandle)
	{
	case BufferType::ArrayBuffer:
		BufferType = GL_ARRAY_BUFFER;
		break;
	case BufferType::ElementBuffer:
		BufferType = GL_ELEMENT_ARRAY_BUFFER;
		break;
	default:
		BufferType = 0;
		break;
	}

	switch (BufferDrawType)
	{
	case BufferUsage::StaticDraw:
		DrawType = GL_STATIC_DRAW;
		break;
	case BufferUsage::DynamicDraw:
		DrawType = GL_DYNAMIC_DRAW;
		break;
	default:
		DrawType = 0;
		break;
	}
	glBufferData(BufferType, sizeof(BufferData), &BufferData, DrawType);
}

void BufferBase::GenerateBuffer(const uint Count)
{
	switch (BufferHandle)
	{
	case BufferType::ArrayObject:
		glGenVertexArrays(Count, &BufferId);
		break;
	case BufferType::ArrayBuffer:
		glGenBuffers(Count, &BufferId);
		break;
	case BufferType::ElementBuffer:
		glGenBuffers(Count, &BufferId);
		break;
	default:
		break;
	}
}

void BufferBase::BindBuffer()
{
	switch (BufferHandle)
	{
	case BufferType::ArrayObject:
		glBindVertexArray(BufferId);
		break;
	case BufferType::ArrayBuffer:
		glBindBuffer(GL_ARRAY_BUFFER, BufferId);
		break;
	case BufferType::ElementBuffer:
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BufferId);
		break;
	default:
		break;
	}
}

