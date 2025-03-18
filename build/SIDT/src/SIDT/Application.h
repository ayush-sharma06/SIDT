#pragma once

#include "Core.h"
#include "Window.h"

namespace SIDT {
	class SIDT_API Application
	{
	public:
		Application();
		virtual ~Application(); // why is it defined virtual?

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be defined in Client
	Application* CreateApplication();
}

