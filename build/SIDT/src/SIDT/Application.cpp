#include "sdpch.h"

#include "Application.h"


namespace SIDT {

	Application* Application::s_Instance = nullptr;

	Application::Application() 
	{
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(SD_BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application() { }

	void Application::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}
	
	void Application::PushOverlay(Layer* Overlay) {
		m_LayerStack.PushOverlayer(Overlay);
		Overlay->OnAttach();

	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowCloseEvent>(SD_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(SD_BIND_EVENT_FN(Application::OnWindowResize));
		dispatcher.Dispatch<WindowMovedEvent>(SD_BIND_EVENT_FN(Application::OnWindowMoved));
		dispatcher.Dispatch<KeyPressedEvent>(SD_BIND_EVENT_FN(Application::OnKeyPressed));
		dispatcher.Dispatch<KeyReleasedEvent>(SD_BIND_EVENT_FN(Application::OnKeyReleased));
		dispatcher.Dispatch<KeyTypedEvent>(SD_BIND_EVENT_FN(Application::OnKeyTyped));
		dispatcher.Dispatch<MouseButtonPressedEvent>(SD_BIND_EVENT_FN(Application::OnMouseButtonPressed));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(SD_BIND_EVENT_FN(Application::OnMouseButtonReleased));
		dispatcher.Dispatch<MouseMovedEvent>(SD_BIND_EVENT_FN(Application::OnMouseMoved));
		dispatcher.Dispatch<MouseScrolledEvent>(SD_BIND_EVENT_FN(Application::OnMouseScrolled));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(e);
			if (e.Handled) break;
		}
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
			for (Layer* layer : m_LayerStack) {
				layer->OnUpdate();
			}
			m_Window->OnUpdate();
		}
	}
}