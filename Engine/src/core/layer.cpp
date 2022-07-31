#include "precompiled.h"
#include "layer.h"

namespace Engine
{

	Layer::Layer(const std::string& name)
		:m_debugName(name)
	{
	}

	Layer::~Layer()
	{
	}

	void Layer::onAttach()
	{
	}

	void Layer::onDetach()
	{
	}

	void Layer::onUpdate()
	{
	}

	void Layer::onEvent(Event& event)
	{
	}
}