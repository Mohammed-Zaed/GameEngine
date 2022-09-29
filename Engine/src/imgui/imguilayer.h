#pragma once
#include "core/layer.h"
#include "events/app_event.h"
#include "events/key_event.h"
#include "events/mouse_event.h"

namespace Engine
{
	class ENGINE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void onAttach() override;
		virtual void onDetach() override;
		virtual void onImGuiRender() override;

		void begin();
		void end();

	private:

		float m_time = 0.0F;
	};
}