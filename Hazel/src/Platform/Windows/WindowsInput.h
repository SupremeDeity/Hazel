#pragma once

#include "Hazel\Input.h"

namespace Hazel {
	class WindowsInput : public Input {
		// Inherited via Input
		virtual bool isKeyPressedImpl(int keycode) override;
		virtual bool isMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMousePosXImpl() override;
		virtual float GetMousePosYImpl() override;
	};
}