#pragma once

#include "SIDT/Core.h"
#include "Layer.h"


namespace SIDT {
	class SIDT_API LayerStack {
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlayer(Layer* Overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* Overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
		

	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	};
}