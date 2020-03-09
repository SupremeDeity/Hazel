#include "hzpch.h"

#include "LayerStack.h"

Hazel::LayerStack::LayerStack()
{
	m_LayerInsert = m_Layers.begin();
}

Hazel::LayerStack::~LayerStack()
{
	// Will Delete The Layers
	for (Layer* layer : m_Layers)
		delete layer;
}

void Hazel::LayerStack::PushLayer(Layer * layer)
{
	m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
}

void Hazel::LayerStack::PushOverlay(Layer * layer)
{
	m_Layers.emplace_back(layer);
}

void Hazel::LayerStack::PopLayer(Layer * overlay)
{
	auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);

	if (it != m_Layers.end()) {
		m_Layers.erase(it);
		m_LayerInsert--;
	}

}

void Hazel::LayerStack::PopOverlay(Layer * overlay)
{
	auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);

	if (it != m_Layers.end()) {
		m_Layers.erase(it);
	}
}
