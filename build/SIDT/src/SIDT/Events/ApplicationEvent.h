#pragma once

#include "Event.h"


namespace SIDT {
	class SIDT_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {
		}
		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}
		EVENT_CLASS_TYPE(WindowResize);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);

	private:
		unsigned int m_Width, m_Height;
	};

	class SIDT_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowCloseEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	class SIDT_API WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowFocusEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowFocus);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	class SIDT_API WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowLostFocusEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowLostFocus);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	class SIDT_API WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(int x, int y)
			: m_WindowX(x), m_WindowY(y)
		{

		}

		inline int GetX() const { return m_WindowX; }
		inline int GetY() const { return m_WindowY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowMovedEvent: ("<<m_WindowX<<", "<<m_WindowY<<")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowMoved);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);

	private:
		int m_WindowX, m_WindowY;
	};

	class SIDT_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "AppTickEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(AppTick);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	class SIDT_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "AppUpdateEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(AppUpdate);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	class SIDT_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "AppRenderEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(AppRender);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};
}