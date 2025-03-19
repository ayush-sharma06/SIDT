#include "sdpch.h"
#include "ImGuiLayer.h"
#include "SIDT/Core.h"
#include "imgui.h"
#include "SIDT/Platform/OpenGL/ImGuiOpenGlRenderer.h"
#include "SIDT/Application.h"

// Temporary
#include "glad/glad.h"
#include "GLFW/glfw3.h"


namespace SIDT {

	ImGuiLayer::ImGuiLayer()
		:Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::OnDetach()
	{
	}


	void ImGuiLayer::OnAttach() {
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();

		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnUpdate() {
		ImGuiIO& io = ImGui::GetIO();

		Application& app = Application::Get();

		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());
		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;
		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowCloseEvent>(SD_BIND_EVENT_FN(ImGuiLayer::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(SD_BIND_EVENT_FN(ImGuiLayer::OnWindowResize));
		dispatcher.Dispatch<WindowMovedEvent>(SD_BIND_EVENT_FN(ImGuiLayer::OnWindowMoved));
		dispatcher.Dispatch<KeyPressedEvent>(SD_BIND_EVENT_FN(ImGuiLayer::OnKeyPressed));
		dispatcher.Dispatch<KeyReleasedEvent>(SD_BIND_EVENT_FN(ImGuiLayer::OnKeyReleased));
		dispatcher.Dispatch<KeyTypedEvent>(SD_BIND_EVENT_FN(ImGuiLayer::OnKeyTyped));
		dispatcher.Dispatch<MouseButtonPressedEvent>(SD_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressed));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(SD_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleased));
		dispatcher.Dispatch<MouseMovedEvent>(SD_BIND_EVENT_FN(ImGuiLayer::OnMouseMoved));
		dispatcher.Dispatch<MouseScrolledEvent>(SD_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolled));
	}

	bool ImGuiLayer::OnWindowClose(WindowCloseEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		/*ImGui::End();*/
		SD_CORE_INFO("ImGui Layer: {0}", e.ToString());
		return false;
	}

	bool ImGuiLayer::OnWindowResize(WindowResizeEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.GetWidth(), e.GetHeight());
		/*SD_CORE_INFO("{0}", e.ToString());*/
		return false;
	}

	bool ImGuiLayer::OnWindowMoved(WindowMovedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		/*SD_CORE_INFO("{0}", e.ToString());*/
		float newX = e.GetX(), newY = e.GetY();
		ImGui::SetNextWindowPos(ImVec2(newX, newY));
		return false;
	}

	bool ImGuiLayer::OnKeyPressed(KeyPressedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		int keycode = e.GetKeyCode();
		if (keycode < ImGuiKey_NamedKey_BEGIN || keycode > ImGuiKey_NamedKey_END) return false;
		io.AddKeyEvent(static_cast<ImGuiKey>(keycode), true);
		io.AddKeyEvent(ImGuiKey_ModCtrl, e.GetKeyCode() == GLFW_KEY_LEFT_CONTROL || e.GetKeyCode( ) == GLFW_KEY_RIGHT_CONTROL);
		io.AddKeyEvent(ImGuiKey_ModShift, e.GetKeyCode() == GLFW_KEY_LEFT_SHIFT || e.GetKeyCode() == GLFW_KEY_RIGHT_SHIFT);
		io.AddKeyEvent(ImGuiKey_ModAlt, e.GetKeyCode() == GLFW_KEY_LEFT_ALT || e.GetKeyCode() == GLFW_KEY_RIGHT_ALT);
		io.AddKeyEvent(ImGuiKey_ModSuper, e.GetKeyCode() == GLFW_KEY_LEFT_SUPER || e.GetKeyCode() == GLFW_KEY_RIGHT_SUPER);
		/*SD_CORE_INFO("{0}", e.ToString());*/
		return false;
	}

	bool ImGuiLayer::OnKeyReleased(KeyReleasedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		int keycode = e.GetKeyCode();
		if (keycode < ImGuiKey_NamedKey_BEGIN || keycode > ImGuiKey_NamedKey_END) return false;
		io.AddKeyEvent(static_cast<ImGuiKey>(keycode), false);
		/*SD_CORE_INFO("{0}", e.ToString());*/
		return false;
	}

	bool ImGuiLayer::OnKeyTyped(KeyTypedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		int keycode = e.GetKeyCode();
		if (keycode > 0 && keycode < 0x10000) io.AddInputCharacter((unsigned int)keycode);
		/*SD_CORE_INFO("{0}", e.ToString());*/
		return false;
	}

	bool ImGuiLayer::OnMouseButtonPressed(MouseButtonPressedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;
		/*SD_CORE_INFO("{0}", e.ToString());*/
		return false;
	}

	bool ImGuiLayer::OnMouseButtonReleased(MouseButtonReleasedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;
		/*SD_CORE_INFO("{0}", e.ToString());*/
		return false;
	}

	bool ImGuiLayer::OnMouseMoved(MouseMovedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());
		/*SD_CORE_INFO("{0}", e.ToString());*/
		return false;
	}

	bool ImGuiLayer::OnMouseScrolled(MouseScrolledEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += e.GetXOffset();
		io.MouseWheel += e.GetYOffset();
		/*SD_CORE_INFO("{0}", e.ToString());*/
		return false;
	}
}