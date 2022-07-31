#include "precompiled.h"
#include "layerstack.h"

namespace Engine
{
	LayerStack::LayerStack()
	{
		m_layerIt = m_layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_layers)
		{
			delete layer;
		}
	}

	void LayerStack::pushLayer(Layer* layer)
	{
		m_layerIt = m_layers.emplace(m_layerIt, layer);
	}

	void LayerStack::pushOverlay(Layer* overlay)
	{
		m_layers.emplace_back(overlay);
	}

	void LayerStack::popLayer(Layer* layer)
	{
		auto it = std::find(m_layers.begin(), m_layers.end(), layer);

		if (it != m_layers.end())
		{
			m_layers.erase(it);
			m_layerIt--;
		}
	}

	void LayerStack::popOverlay(Layer* overlay)
	{
		auto it = std::find(m_layers.begin(), m_layers.end(), overlay);

		if (it != m_layers.end())
		{
			m_layers.erase(it);
		}
	}
}
