#pragma once
#include <glm\glm.hpp>
#include "Hazel\Renderer\VertexArray.h"

namespace Hazel
{

	class RendererAPI
	{
	public:
		enum API
		{
			None = 0, OpenGL = 1
		};

		inline static API& GetAPI() { return s_API; }

		virtual void Init() = 0;
		virtual void Clear() = 0;
		virtual void ClearColor(glm::vec4 color) = 0;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;

	private:
		static API s_API;
	};
}