#pragma once

#include "Core.h"

namespace SIDT {
	class SIDT_API Application
	{
	public:
		Application();
		virtual ~Application(); // why is it defined virtual?

		void Run();
	};

	//To be defined in Client
	Application* CreateApplication();
}

