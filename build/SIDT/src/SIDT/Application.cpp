#include "sdpch.h"

#include "Application.h"


namespace SIDT {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application() {}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));
		dispatcher.Dispatch<WindowMovedEvent>(BIND_EVENT_FN(OnWindowMoved));
		dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(OnKeyPressed));
		dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FN(OnKeyReleased));
		dispatcher.Dispatch<KeyTypedEvent>(BIND_EVENT_FN(OnKeyTyped));
		dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(OnMouseButtonPressed));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FN(OnMouseButtonReleased));
		dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(OnMouseMoved));
		dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FN(OnMouseScrolled));
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		SD_CORE_INFO("{0}", e.ToString());
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e) {
		SD_CORE_INFO("{0}", e.ToString());
		return true;
	}

	bool Application::OnWindowMoved(WindowMovedEvent& e) {
		SD_CORE_INFO("{0}", e.ToString());
		return true;
	}

	bool Application::OnKeyPressed(KeyPressedEvent& e) {
		SD_CORE_INFO("{0}", e.ToString());
		return true;
	}

	bool Application::OnKeyReleased(KeyReleasedEvent& e) {
		SD_CORE_INFO("{0}", e.ToString());
		return true;
	}

	bool Application::OnKeyTyped(KeyTypedEvent& e) {
		SD_CORE_INFO("{0}", e.ToString());
		return true;
	}

	bool Application::OnMouseButtonPressed(MouseButtonPressedEvent& e) {
		SD_CORE_INFO("{0}", e.ToString());
		return true;
	}

	bool Application::OnMouseButtonReleased(MouseButtonReleasedEvent& e) {
		SD_CORE_INFO("{0}", e.ToString());
		return true;
	}

	bool Application::OnMouseMoved(MouseMovedEvent& e) {
		SD_CORE_INFO("{0}", e.ToString());
		return true;
	}

	bool Application::OnMouseScrolled(MouseScrolledEvent& e) {
		SD_CORE_INFO("{0}", e.ToString());
		return true;
	}

	void Application::Run()
	{
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}
}