#include "hzpch.h"
#include "WindowsInput.h"

#include <GLFW\glfw3.h>
#include "Hazel\Application.h"

namespace Hazel {
	Input* Input::m_Instance = new WindowsInput();

	bool WindowsInput::isKeyPressedImpl(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto status = glfwGetKey(window, keycode);
		return status == GLFW_PRESS || status == GLFW_REPEAT;
	}

	bool WindowsInput::isMouseButtonPressedImpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto status = glfwGetMouseButton(window, button);
		return status == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return { (float)xpos, (float)ypos };
	}

	float WindowsInput::GetMousePosXImpl()
	{
		auto [x, y] = GetMousePositionImpl();

		return x;
	}

	float WindowsInput::GetMousePosYImpl()
	{
		auto [x, y] = GetMousePositionImpl();

		return y;
	}
}