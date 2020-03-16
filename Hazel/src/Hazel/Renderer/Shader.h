#pragma once

#include <string>
#include <glm\glm.hpp>

namespace Hazel {
	class Shader {
	public:
		virtual ~Shader() {};

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual void UploadMat4f(const char* name, const glm::mat4& vec) = 0;


		static Shader* Create(const std::string& vertexPath, const std::string& fragmentPath);


	private:
		static std::string GetShaderSource(const std::string& path);
	};
}