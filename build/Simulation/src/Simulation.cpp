#include "SIDT.h"


class ExampleLayer : public SIDT::Layer {
public:
	ExampleLayer()
		:Layer("SIDT Example Layer") { }


	void OnUpdate() override {
		/*SD_TRACE("Example Layer : Update");*/
		if (SIDT::Input::IsKeyPressed(SIDT_KEY_TAB)) SD_TRACE("Tab Key Pressed");
	}

	void OnEvent(SIDT::Event& event) {
		/*SD_TRACE("Layer: {0}", event.ToString());*/
		if (event.GetEventType() == SIDT::EventType::KeyPressed)
		{
			SIDT::KeyPressedEvent& e = (SIDT::KeyPressedEvent&)event;
			if (e.GetKeyCode() == SIDT_KEY_TAB) SD_TRACE("Tab Key Pressed Event");
			SD_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Simulation : public SIDT::Application
{
public:
	Simulation() 
	{
		PushLayer(new ExampleLayer);
		PushOverlay(new SIDT::ImGuiLayer());
	}
	~Simulation() {}
};

SIDT::Application* SIDT::CreateApplication()
{
	return new Simulation();
}