#pragma once
#include "Hazel\Renderer\VertexArray.h"
#include "Hazel\Renderer\RendererAPI.h"
#include "Hazel\Renderer\OrthographicCamera.h"
#include "Hazel\Renderer\Shader.h"

namespace Hazel {

	class Renderer {
	public:
		static void Init();

		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();

		// Binds the vertex array and submits VA for Draw to RendererAPI
		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray, glm::mat4 transform = glm::mat4(1.0f));

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* m_SceneData;
	};
}