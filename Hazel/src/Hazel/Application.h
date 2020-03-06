#pragma once
#include "Core.h"

namespace Hazel {
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	
	// To Be Defined in CLIENT for app registeration.
	Hazel::Application* CreateApplication();
}