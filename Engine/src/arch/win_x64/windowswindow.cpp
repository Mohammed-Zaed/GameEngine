#include "precompiled.h"
#include "WindowsWindow.h"

#include "events/app_event.h"
#include "events/key_event.h"
#include "events/mouse_event.h"

#include "glad/glad.h"

namespace Engine {

	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error_code, const char* description)
	{
		ENGINE_CORE_ERROR("GLFW Error ({0}) {1}", error_code, description);
	}

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
			
			glfwSetErrorCallback(GLFWErrorCallback);

			s_GLFWInitialized = true;
		}

		m_window = glfwCreateWindow((int)config.m_width, (int)config.m_height, m_data.m_title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_data);
		setVSync(true);

		glfwSetWindowSizeCallback(m_window, [] (GLFWwindow* window, int width, int height)
		{

			WindowData& data = *(reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window)));
			data.m_width = width;
			data.m_height = height;

			WindowResizeEvent event(width, height);
			data.m_eventCallback(event);

		});

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {

			WindowData& data = *(reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window)));

			WindowCloseEvent event;
			data.m_eventCallback(event);
		});

		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{

			WindowData& data = *(reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window)));

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.m_eventCallback(event);
				}
				break;

				case GLFW_RELEASE:
				{
					keyReleaseEvent event(key);
					data.m_eventCallback(event);
				}
				break;

				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.m_eventCallback(event);
				}
				break;
			}
		
		});

		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.m_eventCallback(event);
				}
				break;

				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.m_eventCallback(event);
				}
				break;
			}
		});

		glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.m_eventCallback(event);
		});

		glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xPos, (float)yPos);
			data.m_eventCallback(event);
		});

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ENGINE_CORE_ASSERT(status, "Failed to initialise glad");
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
