#pragma once
#include "Hazel\Renderer\RendererAPI.h"
#include "Hazel\Renderer\VertexArray.h"
#include <glm\glm.hpp>

namespace Hazel
{
	class OpenGLRendererAPI : public RendererAPI
	{
		// Inherited via RendererAPI
		virtual void Clear() override;
		virtual void ClearColor(glm::vec4 color) override;
		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) override;
	};
}