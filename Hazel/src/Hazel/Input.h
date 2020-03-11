#pragma once

#include "Hazel/Core.h"

namespace Hazel {
	class HAZEL_API Input {
	public:
		inline static bool isKeyPressed(int keycode) { return m_Instance->isKeyPressedImpl(keycode); };
		inline static bool isMouseButtonPressed(int button) { return m_Instance->isMouseButtonPressed(button); };
		inline static std::pair<float, float> GetMousePosition() { return m_Instance->GetMousePositionImpl(); }
		inline static float GetMousePosX() { return m_Instance->GetMousePosXImpl(); };
		inline static float GetMousePosY() { return m_Instance->GetMousePosYImpl(); };
	protected:
		virtual bool isKeyPressedImpl(int keycode) = 0;
		virtual bool isMouseButtonPressedImpl(int button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMousePosXImpl() = 0;
		virtual float GetMousePosYImpl() = 0;
	private:
		static Input* m_Instance;
	};
}