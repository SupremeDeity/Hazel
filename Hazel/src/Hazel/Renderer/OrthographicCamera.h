#pragma once

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

namespace Hazel
{
	class OrthographicCamera
	{
	public:
		OrthographicCamera(float left, float right, float bottom, float top);

		inline const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
		inline const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		inline const glm::mat4& GetProjectionViewMatrix() const { return m_ProjectionViewMatrix; }

		inline const glm::vec3& GetPosition() { return m_Position; }
		inline void SetPosition(glm::vec3& position) { m_Position = position; }

		inline const float GetRotation() { return m_Rotation; }
		inline void SetRotation(float rotation) { m_Rotation = rotation; }

	private:
		void RecalculateViewMatrix();
	private:
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ProjectionViewMatrix;

		glm::vec3 m_Position = {0.0f, 0.0f, 0.0f};
		float m_Rotation = 0.0f;
	};
}