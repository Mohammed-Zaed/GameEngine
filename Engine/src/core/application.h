#include "core.h"
#include "window.h"

namespace Engine
{
	class ENGINE_API Application
	{

	public:
		Application();
		virtual ~Application();

		void run();

	private:
		std::unique_ptr<Window> m_window;
		bool m_running = true;
	};

	//To be defined by client
	Application* createApplication();
}