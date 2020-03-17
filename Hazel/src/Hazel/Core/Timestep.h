#pragma once

namespace Hazel
{
	class Timestep
	{
	public:
		Timestep(float time) : m_Time(time) {};

		float GetTimeInSeconds() { return m_Time; }
		float GetTimeInMilliSeconds() { return m_Time * 1000.0f; }

		operator float() const { return m_Time; }

	private:
		float m_Time;
	};
}
