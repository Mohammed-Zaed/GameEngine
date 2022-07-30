#pragma once

#include "precompiled.h"
#include "core/core.h"


namespace Engine
{
	enum class EventType
	{
		NONE = 0,
		WINDOW_CLOSE_EVENT, WINDOW_RESIZE_EVENT, WINDOW_FOCUS_EVENT, WINDOW_LOST_FOCUS_EVENT, WINDOW_MOVED_EVENT,
		APP_TICK_EVENT, APP_UPDATE_EVENT, APP_RENDER_EVENT,
		KEY_PRESS_EVENT, KEY_RELEASE_EVENT,
		MOUSE_BUTTON_PRESS_EVENT, MOUSE_BUTTON_RELEASED_EVENT, MOUSE_MOVED_EVENT, MOUSE_SCROLLED_EVENT
	};

	enum class EventCategory
	{
		NONE							=	0,
		EVENT_CATEGORY_APPLICATION		=	BIT(0),
		EVENT_CATEGORY_INPUT			=	BIT(1),
		EVENT_CATEGORY_KEYBOARD			=	BIT(2),
		EVENT_CATEGORY_MOUSE			=	BIT(3),
		EVENT_CATEGORY_MOUSE_BUTTON		=	BIT(4)
	};

	class ENGINE_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType getType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlag() const = 0;

		virtual std::string toString() const { return getName(); }
		bool isCategory(EventCategory category)
		{ 
			return static_cast<bool>(getCategoryFlag() & static_cast<int>(category));
		}

	protected:
		bool m_handled = false;

	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_event(event)
		{
		}

		template<typename T>
		using eventFun = std::function<bool(T&)>;

		template<typename T>
		bool dispatch(eventFun<T> func)
		{
			if (m_event.getType() == T::getStaticEventType())
			{
				m_event.m_handled = func(*(T*)&m_event);
				return true;
			}
			return false;
		}
	private:
		Event& m_event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& event)
	{
		return os << event.toString();
	}

#define EVENT_CLASS_TYPE(eventType)	static EventType getStaticEventType() { return EventType::##eventType; }\
									virtual EventType getType() const override { return getStaticEventType(); }\
									virtual const char* getName() const override { return #eventType; } 
									
#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlag() const override { return category; }

}