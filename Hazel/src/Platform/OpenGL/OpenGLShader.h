#pragma once

#include "Hazel\Renderer\Shader.h"
#include <glm\glm.hpp>

namespace Hazel {
	class OpenGLShader : public Shader {
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~OpenGLShader();

		// Inherited via Shader
		virtual void Bind() const override;
		virtual void Unbind() const override;

		void UploadUniformInt(const char* name, int value);

		void UploadUniformFloat(const char* name, float value);
		void UploadUniformFloat2(const char* name, const glm::vec2& vec);
		void UploadUniformFloat3(const char* name, const glm::vec3& vec);
		void UploadUniformFloat4(const char* name, const glm::vec4& vec);

		void UploadUniformMat3(const char* name, const glm::mat3& mat);
		void UploadUniformMat4(const char* name, const glm::mat4& mat);
	
	private:
		uint32_t m_RendererID;
	private:
		unsigned int CreateShader(unsigned int Type, const std::string & src);
	};
}