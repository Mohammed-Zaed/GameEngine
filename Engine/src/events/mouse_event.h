#pragma once
 
#include <sstream>
#include "event.h"

namespace Engine
{
	class ENGINE_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			:m_x(x), m_y(y)
		{

		}

		inline float getx() const { return m_x; }
		inline float gety() const { return m_y; }

		virtual std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent : " << getx() << ", " << gety();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MOUSE_MOVED_EVENT)
		EVENT_CLASS_CATEGORY(static_cast<int>(EventCategory::EVENT_CATEGORY_MOUSE) | static_cast<int>(EventCategory::EVENT_CATEGORY_INPUT))

	private:
		float m_x;
		float m_y;
	};

	class ENGINE_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_xOffset(xOffset), m_yOffset(yOffset) {}

		inline float getXOffset() const { return m_xOffset; }
		inline float getYOffset() const { return m_yOffset; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << getXOffset() << ", " << getYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MOUSE_SCROLLED_EVENT)
		EVENT_CLASS_CATEGORY(static_cast<int>(EventCategory::EVENT_CATEGORY_MOUSE) | static_cast<int>(EventCategory::EVENT_CATEGORY_INPUT))

	private:
		float m_xOffset;
		float m_yOffset;
	};

	class ENGINE_API MouseButtonEvent : public Event
	{
	public:
		inline int getMouseButton() const { return m_button; }

		EVENT_CLASS_CATEGORY(
								static_cast<int>(EventCategory::EVENT_CATEGORY_MOUSE_BUTTON) | 
								static_cast<int>(EventCategory::EVENT_CATEGORY_INPUT)        |
								static_cast<int>(EventCategory::EVENT_CATEGORY_MOUSE)
							)

	protected:
		MouseButtonEvent(int button)
			: m_button(button) {}

		int m_button;
	};

	class ENGINE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent : " << getMouseButton();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MOUSE_BUTTON_PRESS_EVENT)
	};

	class ENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << getMouseButton();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MOUSE_BUTTON_RELEASED_EVENT)
	};
}