#include "hzpch.h"
#include "Shader.h"
#include <glad\glad.h>
#include "Hazel\Renderer\Renderer.h"
#include "Platform\OpenGL\OpenGLShader.h"

namespace Hazel {
	Shader* Shader::Create(const std::string & vertexPath, const std::string & fragmentPath)
	{
		switch (Renderer::GetAPI()) {
		case RendererAPI::NONE:
			HZ_CORE_ASSERT(false, "RendererAPI::NONE not supported!");
			return nullptr;

		case RendererAPI::OPENGL:
			return new OpenGLShader(GetShaderSource(vertexPath), GetShaderSource(fragmentPath));
		}

		HZ_CORE_ASSERT(false, "Unknown API Selected!");
		return nullptr;
	}

	std::string Shader::GetShaderSource(const std::string & path)
	{
		std::ifstream stream(path);

		std::string line;
		std::string str;
		if(stream.is_open()) {
			while(std::getline(stream, line)) {
				str = str + line + "\n";
			}
			return str;
		}
		else {
			HZ_CORE_ASSERT(false, "Shader File Invalid!");
			return std::string();
		}

		return std::string();
	}
}