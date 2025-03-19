#pragma once

#include "SIDT/Core.h"
#include "SIDT/Events/Event.h"

namespace SIDT {
	class SIDT_API Layer {

	public:
		Layer(const std::string& name = "Layer");
		~Layer();
		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e) {}

		inline const std::string& GetName() { return m_DebugName; }

	private:
		std::string m_DebugName;
	};
}