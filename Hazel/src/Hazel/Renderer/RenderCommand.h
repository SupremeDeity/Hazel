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

		inline static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) { s_RendererAPI->SetViewport(x, y, width, height); }

		inline static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray, uint32_t indexCount = 0)
		{
			s_RendererAPI->DrawIndexed(vertexArray, indexCount);
		}
	private:
		static Scope<RendererAPI> s_RendererAPI;
	};
}