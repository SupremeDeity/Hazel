#include <Hazel.h>
#include <Hazel/Events/Event.h>

class ELayer : public Hazel::Layer {
public:
	ELayer() : Layer("ELayer") {}

	void OnUpdate() override {
		HZ_INFO("ELayer Update.");
	}

	void OnEvent(Hazel::Event& event) override {
		HZ_TRACE("{0}", event);
	}
};

class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ELayer());
		PushOverlay(new Hazel::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}