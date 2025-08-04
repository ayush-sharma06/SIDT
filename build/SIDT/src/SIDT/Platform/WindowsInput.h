#pragma once

#include "SIDT/Input.h"

namespace SIDT {
	class WindowsInput : public Input {
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<double, double> GetMousePosImpl() override;
		virtual double GetMouseXImpl() override;
		virtual double GetMouseYImpl() override;
	};
}