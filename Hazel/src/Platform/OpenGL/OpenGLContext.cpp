#include "hzpch.h"
#include <glad\glad.h>
#include "OpenGLContext.h"

namespace Hazel {
	OpenGLContext::OpenGLContext(GLFWwindow * WindowHandle)
		: m_Handle(WindowHandle)
	{
		HZ_CORE_ASSERT(WindowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_Handle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HZ_CORE_ASSERT(status, "Failed to initialize Glad!");

		HZ_CORE_INFO("GPU: {0}", glGetString(GL_RENDERER));

		//OpenGL Version: 4.0.0 - Build 10.18.10.4425
		HZ_CORE_INFO("OpenGL Version: {0}", glGetString(GL_VERSION));
	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_Handle);
	}
}