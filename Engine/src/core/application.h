#include "core.h"
#include "window.h"
#include "events/event.h"
#include "events/app_event.h"
#include "core/layerstack.h"

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

	private:
		bool Application::onWindowClose(WindowCloseEvent& event);

		std::unique_ptr<Window> m_window;
		bool m_running = true;

		LayerStack m_layerStack;
	};

	//To be defined by client
	Application* createApplication();
}