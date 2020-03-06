#pragma once

extern Hazel::Application* Hazel::CreateApplication();

#ifdef HZ_PLATFORM_WINDOWS

int main(int argc, char** argv) {
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}
#else 
#error HAZEL ONLY SUPPORTS WINDOWS!
#endif // !HAZEL_PLATFORM_WINDOWS
