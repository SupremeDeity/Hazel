#include "Sandbox2D.h"
#include <Platform\OpenGL\OpenGLShader.h>
#include <sstream>
#include <random>

Sandbox2D::Sandbox2D() 
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	HZ_PROFILE_SCOPE("Clear");

	m_Texture = Hazel::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
	HZ_PROFILE_SCOPE("Clear");
}

void Sandbox2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	ImGui::End();
}

glm::vec4 GetRandomColor()
{
	srand(time(NULL));
	float f1 = rand() % 1 + 0.0f;
	float f2 = rand() % 1 + 0.0f;
	float f3 = rand() % 1 + 0.0f;
	return {f1, f2, f3, 1.0f};
}

void Sandbox2D::OnUpdate(Hazel::Timestep ts)
{
	HZ_PROFILE_FUNCTION();
		m_CameraController.OnUpdate(ts);

	{
		HZ_PROFILE_SCOPE("Renderer Prep");
		Hazel::RenderCommand::ClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Hazel::RenderCommand::Clear();
	}
	{
		HZ_PROFILE_SCOPE("Render Draw");
		Hazel::Renderer2D::BeginScene(m_CameraController.GetCamera());
		//Hazel::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f }, { 1.0f, 1.0f }, glm::radians(45.0f), { 0.8f, 0.2f, 0.3f, 1.0f });
		//Hazel::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.3f, 0.75f }, { 0.3f, 0.2f, 0.8f, 1.0f });
		//Hazel::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		//Hazel::Renderer2D::DrawQuad({ 0.3f, -0.5f, -0.1f }, { 10.0f, 10.0f }, m_Texture);

		for (int x = 0; x < 100; x++)
		{
			for (int y = 0; y < 100; y++)
			{
				Hazel::Renderer2D::DrawQuad({ 0.5 * x, 0.5f * y}, { 0.5f, 0.5f }, { 1.0f, 0.3f, 0.8f, 1.0f });
			}
		}

		Hazel::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnEvent(Hazel::Event & event)
{
	m_CameraController.OnEvent(event);
}
