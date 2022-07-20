#include "application.h"
#include "events/event.h"
#include "events/app_event.h"
#include "core/log.h"

namespace Engine
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::run()
	{
		WindowResizeEvent  windowResizeEvent(1280, 720);

		if (windowResizeEvent.isCategory(EventCategory::EVENT_CATEGORY_APPLICATION))
		{
			ENGINE_CORE_TRACE(windowResizeEvent);
		}
		else
		{
			ENGINE_CORE_TRACE("Category didn't match");
		}

		while (true)
		{

		}
	}
}