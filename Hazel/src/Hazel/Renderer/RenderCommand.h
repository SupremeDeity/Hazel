#pragma once
#include "Hazel\Renderer\VertexArray.h"
#include "Hazel\Renderer\RendererAPI.h"
#include <glm\glm.hpp>

namespace Hazel
{
	class RenderCommand
	{
	public:

		inline static void Init() { s_RendererAPI->Init(); }

		inline static void Clear() { s_RendererAPI->Clear(); }
		inline static void ClearColor(glm::vec4 color) { s_RendererAPI->ClearColor(color); }

		inline static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
		{
			s_RendererAPI->DrawIndexed(vertexArray);
		}
	private:
		static RendererAPI* s_RendererAPI;
	};
}