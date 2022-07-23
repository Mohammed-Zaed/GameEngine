#pragma once

#include "precompiled.h"
#include "event.h"

namespace Engine
{
	class ENGINE_API KeyEvent : public Event
	{
	public:
		int getKeyCode() const
		{
			return m_keyCode;
		}

		EVENT_CLASS_CATEGORY(static_cast<int>(EventCategory::EVENT_CATEGORY_KEYBOARD) | static_cast<int>(EventCategory::EVENT_CATEGORY_INPUT))

	protected:
		KeyEvent(int keycode)
			: m_keyCode(keycode)
		{

		}

		int m_keyCode;
	};

	class ENGINE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, int repeatCount)
			: KeyEvent(keyCode),
			  m_repeateCount(repeatCount)
		{

		}

		virtual std::string toString() const override
		{
			std::stringstream ss;
			ss << "Event: KeypressedEvent: " << m_keyCode << " (repeat count: " << m_repeateCount << ")";
			return ss.str();

		}

		EVENT_CLASS_TYPE(KEY_PRESS_EVENT)

	private:
		int m_repeateCount;
	};

	class ENGINE_API keyReleaseEvent : public KeyEvent
	{
	public:
		keyReleaseEvent(int keyCode)
			:KeyEvent(keyCode)
		{

		}

		virtual std::string toString() const override
		{
			std::stringstream ss;
			ss << "Event: KeyReleaseEvent: " << m_keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KEY_RELEASE_EVENT)

	};
}