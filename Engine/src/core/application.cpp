#include "precompiled.h"
#include "application.h"
#include "events/app_event.h"
#include "events/event.h"
#include "core/log.h"
#include "GLFW/glfw3.h"

namespace Engine
{
	Application::Application()
	{
		m_window = std::unique_ptr<Window>(Window::create());
		m_window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
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

	void Application::onEvent(Event& event)
	{
		EventDispatcher eventDispatcher(event);
		eventDispatcher.dispatch<WindowCloseEvent>(std::bind(&Application::onWindowClose, this, std::placeholders::_1));
		ENGINE_CORE_TRACE("{0}", event);
	}

	bool Application::onWindowClose(WindowCloseEvent& event)
	{
		m_running = false;
		return true;
	}
}