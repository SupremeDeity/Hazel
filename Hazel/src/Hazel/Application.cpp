#include "hzpch.h"

#include "Hazel/Application.h"
#include "Hazel/Log.h"

#include <glad\glad.h>

namespace Hazel {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::m_Instance = nullptr;

	Application::Application() 
	{
		HZ_CORE_ASSERT(!m_Instance, "Application already exists!");
		m_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		
		// We are basically passing in OnEvent(_PlaceHolder) function here. 
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
	}

	/* The GLFW Window Callbacks call this function with the HAZEL Events as the parameter. All Hazel Events are Inherited from the base class Event */
	void Application::OnEvent(Event& e)
	{
		/* This Dispatcher is really simple. Basically Takes in our Hazel Event from OnEvent (which actually gets set in the glfw callback lambdas we created). It then checks if this Event is Equal to the Event we provided in Dispatch<>. and if it is, Basically Calls the Dispatcher Function Provided with the Event from OnEvent (just passes in the reference we gave into it from initialization ). */
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}

		HZ_CORE_TRACE("{0}", e);
	}

	void Application::PushLayer(Layer * layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer * layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}