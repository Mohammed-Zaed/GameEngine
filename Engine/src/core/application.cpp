#include "precompiled.h"
#include "application.h"
#include "events/event.h"
#include "events/app_event.h"
#include "core/log.h"
#include "GLFW/glfw3.h"

namespace Engine
{
	Application::Application()
	{
		m_window = std::unique_ptr<Window>(Window::create());
	}

	Application::~Application()
	{

	}

	void Application::run()
	{
		WindowResizeEvent  windowResizeEvent(1280, 720);

		while (m_running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_window->onUpdate();

		}
	}
}