#pragma once
#include "Hazel.h"

namespace Hazel {

	struct FramebufferSpecification {
		int Width, Height;

		bool isSwapChain = false;
	};

	class Framebuffer {
	public:
		virtual ~Framebuffer() = default;
		static Ref<Framebuffer> Create(const FramebufferSpecification& spec);

		virtual const FramebufferSpecification GetFramebufferSpecification() const = 0;
		virtual const uint32_t GetColorAttachmentID() const = 0;
		virtual void Resize(uint32_t width, uint32_t height) = 0;
		virtual void Bind() = 0;
		virtual void Unbind() = 0;
	};
}