#include "core.h"
#include "window.h"
#include "events/event.h"
#include "events/app_event.h"
#include "core/layerstack.h"
#include "imgui/imguilayer.h"

namespace Engine
{
	class ENGINE_API Application
	{

	public:
		Application();
		virtual ~Application();

		void run();
		void onEvent(Event& event);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* overlay);

		inline const Window& getWindow() const { return *m_window;}
		inline static Application& getInstance() { return *m_instance; }


	private:
		bool Application::onWindowClose(WindowCloseEvent& event);

		std::unique_ptr<Window> m_window;
		ImGuiLayer* m_imGuiLayer;
		bool m_running = true;

		LayerStack m_layerStack;

		static Application* m_instance;
	};

	//To be defined by client
	Application* createApplication();
}