#include "hzpch.h"
#include "OpenGLShader.h"
#include <glad\glad.h>
#include <glm\gtc\type_ptr.hpp>

namespace Hazel {
	OpenGLShader::OpenGLShader(const std::string & vertexSrc, const std::string & fragmentSrc)
	{
		// Create an empty vertex shader handle
	GLuint vertexShader = CreateShader(GL_VERTEX_SHADER, vertexSrc);
	GLuint fragmentShader = CreateShader(GL_FRAGMENT_SHADER, fragmentSrc);

	m_RendererID = glCreateProgram();

	// Attach our shaders to our program
	glAttachShader(m_RendererID, vertexShader);
	glAttachShader(m_RendererID, fragmentShader);

	// Link our program
	glLinkProgram(m_RendererID);

	// Note the different functions here: glGetProgram* instead of glGetShader*.
	GLint isLinked = 0;
	glGetProgramiv(m_RendererID, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(m_RendererID, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(m_RendererID, maxLength, &maxLength, &infoLog[0]);

		// We don't need the program anymore.
		glDeleteProgram(m_RendererID);
		// Don't leak shaders either.
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		// Use the infoLog as you see fit.
		HZ_CORE_ERROR("{0}", infoLog.data());
		HZ_CORE_ASSERT(false, "Shader Link Failure!");
		// In this simple program, we'll just leave
		return;
	}

	// Always detach shaders after a successful link.
	glDetachShader(m_RendererID, vertexShader);
	glDetachShader(m_RendererID, fragmentShader);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_RendererID);
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void OpenGLShader::Unbind() const
	{
		glUseProgram(0);
	}

	void OpenGLShader::UploadMat4f(const char* name, const glm::mat4& vec)
	{
		glUniformMatrix4fv(glGetUniformLocation(m_RendererID, name), 1, GL_FALSE, glm::value_ptr(vec));
	}

	unsigned int OpenGLShader::CreateShader(unsigned int Type, const std::string & src)
	{
		unsigned int shader = glCreateShader(Type);
		const GLchar *source = src.c_str();
		glShaderSource(shader, 1, &source, 0);

		// Compile the vertex shader
		glCompileShader(shader);

		GLint isCompiled = 0;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

			// We don't need the shader anymore.
			glDeleteShader(shader);

			HZ_CORE_ERROR("{0}", infoLog.data());
			HZ_CORE_ASSERT(false, (Type == 0x8B31 ? "Vertex Compilation Failed" : "Fragment Compilation Failed"));

			return unsigned int();
		}

		return shader;
	}
}