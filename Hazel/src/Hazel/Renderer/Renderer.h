#pragma once

namespace Hazel {
	enum RendererAPI {
		NONE = 0, OPENGL = 1
	};

	class Renderer {
	public:
		inline static RendererAPI GetAPI() { return m_API; }
	private:
		static RendererAPI m_API;
	};
}