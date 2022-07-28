#include "precompiled.h"
#include "WindowsWindow.h"

namespace Engine {

	static bool s_GLFWInitialized = false;

	Window* Window::create(const WindowsConfiguration& config)
	{
		return new WindowsWindow(config);
	}

	WindowsWindow::WindowsWindow(const WindowsConfiguration& config)
	{
		init(config);
	}

	WindowsWindow::~WindowsWindow()
	{
		shutdown();
	}

	void WindowsWindow::init(const WindowsConfiguration& config)
	{
		m_data.m_title = config.m_title;
		m_data.m_width = config.m_width;
		m_data.m_height = config.m_height;

		ENGINE_CORE_INFO("Creating window {0} ({1}, {2})", config.m_title, config.m_width, config.m_height);

		if (!s_GLFWInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			ENGINE_CORE_ASSERT(success, "Could not intialize GLFW!");

			s_GLFWInitialized = true;
		}

		m_window = glfwCreateWindow((int)config.m_width, (int)config.m_height, m_data.m_title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_data);
		setVSync(true);
	}

	void WindowsWindow::shutdown()
	{
		glfwDestroyWindow(m_window);
	}

	void WindowsWindow::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void WindowsWindow::setVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_data.m_vSync = enabled;
	}

	bool WindowsWindow::isVSync() const
	{
		return m_data.m_vSync;
	}

}
