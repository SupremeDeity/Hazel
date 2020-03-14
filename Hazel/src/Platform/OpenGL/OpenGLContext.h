#pragma once
#include "Hazel\Renderer\GraphicsContext.h"
#include <GLFW\glfw3.h>

namespace Hazel {
	class OpenGLContext : public GraphicsContext {
	public:
		OpenGLContext(GLFWwindow* WindowHandle);
		~OpenGLContext();

		// Inherited via GraphicsContext
		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_Handle;
	};
}