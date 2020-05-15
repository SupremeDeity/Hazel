#pragma once
#include "Texture.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Hazel {
	class SubTexture2D {
	public:
		SubTexture2D(const Ref<Texture2D> Texture, const glm::vec2& min, const glm::vec2& max);

		// Getters
		inline const Ref<Texture2D> GetTexture() const { return m_Texture; }
		inline const glm::vec2* GetTextureCoords() const { return m_TextureCoords; }

		// Helper Function
		static Ref<SubTexture2D> CreateFromCoords(const Ref<Texture2D>& Texture, const glm::vec2& coords, const glm::vec2& cellSize, const glm::vec2& spriteSize = { 1, 1 });
	private:
		Ref<Texture2D> m_Texture;
		glm::vec2 m_TextureCoords[4];
	};
}