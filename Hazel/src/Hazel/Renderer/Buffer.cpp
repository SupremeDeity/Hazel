#include "hzpch.h"

#include "Hazel\Renderer\Buffer.h"
#include "Hazel\Renderer\Renderer.h"
#include "Platform\OpenGL\OpenGLBuffer.h"

namespace Hazel {
	VertexBuffer* VertexBuffer::Create(float * vertices, uint32_t size)
	{
		switch(Renderer::GetAPI()) {
		case RendererAPI::None: 
			HZ_CORE_ASSERT(false, "RendererAPI::NONE not supported!");
			return nullptr;

		case RendererAPI::OpenGL:
			return new OpenGLVertexBuffer(vertices, size);
		}

		HZ_CORE_ASSERT(false, "Unknown API Selected!");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t * indices, uint32_t count)
	{
		switch (Renderer::GetAPI()) {
		case RendererAPI::None:
			HZ_CORE_ASSERT(false, "RendererAPI::NONE not supported!");
			return nullptr;

		case RendererAPI::OpenGL:
			return new OpenGLIndexBuffer(indices, count);
		}

		HZ_CORE_ASSERT(false, "Unknown API Selected!");
		return nullptr;
	}
}