#pragma once

#include <sstream>
#include "event.h"


namespace Engine {

	class ENGINE_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_width(width), m_height(height) {}

		inline unsigned int getWidth() const { return m_width; }
		inline unsigned int getHeight() const { return m_height; }

		virtual std::string toString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << getWidth() << ", " << getHeight();
			return ss.str();
		}

		EVENT_CLASS_TYPE(WINDOW_RESIZE_EVENT)
		EVENT_CLASS_CATEGORY(static_cast<int>(EventCategory::EVENT_CATEGORY_APPLICATION))
	private:
		unsigned int m_width;
		unsigned int m_height;
	};

	class ENGINE_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WINDOW_CLOSE_EVENT)
		EVENT_CLASS_CATEGORY(static_cast<int>(EventCategory::EVENT_CATEGORY_APPLICATION))
	};

	class ENGINE_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(APP_TICK_EVENT)
		EVENT_CLASS_CATEGORY(static_cast<int>(EventCategory::EVENT_CATEGORY_APPLICATION))
	};

	class ENGINE_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(APP_UPDATE_EVENT)
		EVENT_CLASS_CATEGORY(static_cast<int>(EventCategory::EVENT_CATEGORY_APPLICATION))
	};

	class ENGINE_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(APP_RENDER_EVENT)
		EVENT_CLASS_CATEGORY(static_cast<int>(EventCategory::EVENT_CATEGORY_APPLICATION))
	};
}