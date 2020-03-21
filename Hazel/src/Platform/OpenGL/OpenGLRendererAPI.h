#pragma once
#include "Hazel\Renderer\RendererAPI.h"
#include "Hazel\Renderer\VertexArray.h"
#include <glm\glm.hpp>

namespace Hazel
{
	class OpenGLRendererAPI : public RendererAPI
	{
		// Inherited via RendererAPI
		virtual void Init() override;
		virtual void Clear() override;
		virtual void ClearColor(glm::vec4 color) override;
		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) override;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
	};
}