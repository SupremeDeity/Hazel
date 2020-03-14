#pragma once

#include "Hazel\Renderer\Shader.h"

namespace Hazel {
	class OpenGLShader : public Shader {
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~OpenGLShader();

		// Inherited via Shader
		virtual void Bind() const override;
		virtual void Unbind() const override;
	private:
		uint32_t m_RendererID;
	private:
		unsigned int CreateShader(unsigned int Type, const std::string & src);
	};
}