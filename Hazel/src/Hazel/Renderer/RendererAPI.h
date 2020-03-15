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
			NONE = 0, OPENGL = 1
		};

		inline static API& GetAPI() { return s_API; }

		virtual void Clear() = 0;
		virtual void ClearColor(glm::vec4 color) = 0;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;

	private:
		static API s_API;
	};
}