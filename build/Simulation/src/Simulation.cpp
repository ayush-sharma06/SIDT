#include "SIDT.h"


class ExampleLayer : public SIDT::Layer {
public:
	ExampleLayer()
		:Layer("SIDT Example Layer") { }


	void OnUpdate() override {
		SD_TRACE("Example Layer : Update");
	}

	void OnEvent(SIDT::Event& e) {
		SD_TRACE("Layer: {0}", e.ToString());
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