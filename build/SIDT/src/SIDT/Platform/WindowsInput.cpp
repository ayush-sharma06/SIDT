#include "sdpch.h"
#include "WindowsInput.h"
#include "SIDT/Application.h"
#include "GLFW/glfw3.h"


namespace SIDT {

	Input* Input::s_Instance = new WindowsInput;

	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		bool state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		bool state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	std::pair<double, double> WindowsInput::GetMousePosImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		std::pair<double, double> pos;
		glfwGetCursorPos(window, &pos.first, &pos.second);
		return pos;
	}

	double WindowsInput::GetMouseXImpl()
	{
		return GetMousePosImpl().first;
	}

	double WindowsInput::GetMouseYImpl()
	{
		return GetMousePosImpl().first;
	}
}
