#include "core.h"

namespace Engine
{
	class ENGINE_API Application
	{

	public:
		Application();
		virtual ~Application();

		void run();
	};

	//To be defined by client
	Application* createApplication();
}