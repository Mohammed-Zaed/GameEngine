#pragma once
#pragma once

#include "precompiled.h"

#include "core/core.h"
#include "events/event.h"

namespace Engine {

	struct WindowsConfiguration
	{
		std::string m_title;
		unsigned int m_width;
		unsigned int m_height;

		WindowsConfiguration(
			const std::string& title = "Game Engine",
			unsigned int width = 1280,
			unsigned int height = 720
		) : m_title(title), m_width(width), m_height(height)
		{
		}
	};

	// Interface representing a desktop system based Window
	class ENGINE_API Window
	{
	public:
		using eventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		// Window attributes
		virtual void setEventCallback(const eventCallbackFn& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		static Window* create(const WindowsConfiguration& config = WindowsConfiguration());
	};
}