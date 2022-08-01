#pragma once
#include "core/layer.h"

namespace Engine
{
	class ENGINE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void onAttach() override;
		virtual void onDetach() override;

		virtual void onUpdate() override;

		//virtual void onEvent(Event& event) override;



	};
}