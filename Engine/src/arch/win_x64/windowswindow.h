#pragma once

#include "core/window.h"

#include <GLFW/glfw3.h>

namespace Engine {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowsConfiguration& config);
		virtual ~WindowsWindow();

		void onUpdate() override;

		inline unsigned int getWidth() const override { return m_data.m_width; }
		inline unsigned int getHeight() const override { return m_data.m_height; }

		// Window attributes
		inline void setEventCallback(const eventCallbackFn& callback) override { m_data.m_eventCallback = callback; }
		void setVSync(bool enabled) override;
		bool isVSync() const override;
	private:
		virtual void init(const WindowsConfiguration& config);
		virtual void shutdown();
	private:
		GLFWwindow* m_window;

		struct WindowData
		{
			std::string m_title;
			unsigned int m_width, m_height;
			bool m_vSync;

			eventCallbackFn m_eventCallback;
		};

		WindowData m_data;
	};


}