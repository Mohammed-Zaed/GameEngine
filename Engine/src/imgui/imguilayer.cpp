#include "precompiled.h"
#include "arch/opengl/imgui_impl_opengl3.h"
#include "imguilayer.h"
#include "GLFW/glfw3.h"
#include "core/application.h"

namespace Engine
{
	ImGuiLayer::ImGuiLayer()
		:Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::onAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();

		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::onDetach()
	{
	}

	void ImGuiLayer::onUpdate()
	{

		ImGuiIO& io = ImGui::GetIO();
		float time = static_cast<float>(glfwGetTime());
		static bool show = true;

		io.DeltaTime = time > 0.0f ? time : (1.0f / 60.0f);
		const Window& window = Application::getInstance().getWindow();
		io.DisplaySize = ImVec2(window.getWidth(), window.getHeight());


		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
}