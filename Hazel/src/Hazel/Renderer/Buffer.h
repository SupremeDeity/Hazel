#pragma once

namespace Hazel
{
	enum class ShaderDataType
	{
		NONE,
		Float,
		Float2,
		Float3,
		Float4,
		Int,
		Int2,
		Int3,
		Int4,
		Mat3,
		Mat4,
		Bool
	};

	static uint32_t ShaderDataTypeSize(ShaderDataType Type)
	{
		switch (Type)
		{
		case Hazel::ShaderDataType::Float:	return 4;
		case Hazel::ShaderDataType::Float2:	return 4 * 2;
		case Hazel::ShaderDataType::Float3:	return 4 * 3;
		case Hazel::ShaderDataType::Float4:	return 4 * 4;
		case Hazel::ShaderDataType::Int:	return 4;
		case Hazel::ShaderDataType::Int2:	return 4 * 2;
		case Hazel::ShaderDataType::Int3:	return 4 * 3;
		case Hazel::ShaderDataType::Int4:	return 4 * 4;
		case Hazel::ShaderDataType::Mat3:	return 3 * 3 * 4;
		case Hazel::ShaderDataType::Mat4:	return 4 * 4 * 4;
		case Hazel::ShaderDataType::Bool:	return 1;
		default:
			break;
		}

		HZ_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	struct BufferElement
	{
		ShaderDataType Type;
		std::string Name;
		uint32_t Offset;
		uint32_t Size;
		bool Normalized;

		BufferElement() {}

		BufferElement(ShaderDataType type, const std::string& name, bool normalized = false)
			: Type(type), Name(name), Size(ShaderDataTypeSize(Type)),Normalized(normalized)
		{}

		uint32_t GetComponentCount() const
		{
			switch (Type)
			{
			case Hazel::ShaderDataType::Float:	return 1;
			case Hazel::ShaderDataType::Float2: return 2; 
			case Hazel::ShaderDataType::Float3: return 3;
			case Hazel::ShaderDataType::Float4: return 4;
			case Hazel::ShaderDataType::Int:	return 1;
			case Hazel::ShaderDataType::Int2:	return 2;
			case Hazel::ShaderDataType::Int3:	return 3;
			case Hazel::ShaderDataType::Int4:	return 4;
			case Hazel::ShaderDataType::Mat3:	return 3 * 4;
			case Hazel::ShaderDataType::Mat4:	return 4 * 4;
			case Hazel::ShaderDataType::Bool:	return 1;
			default:
				break;
			}
			HZ_CORE_ASSERT(false, "Unknown ShaderDataType!");
			return 0;
		}
	};

	class BufferLayout
	{
	public:
		BufferLayout() {}
		BufferLayout(const std::initializer_list<BufferElement>& element) 
			: m_Elements(element) 
		{
			CalculateStrideAndOffset();
		}

		inline uint32_t GetStride() const { return m_Stride; }
		inline const std::vector<BufferElement>& GetElements() const { return m_Elements; }

		std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); }
		std::vector<BufferElement>::iterator end() { return m_Elements.end(); }
		std::vector<BufferElement>::const_iterator begin() const { return m_Elements.begin(); }
		std::vector<BufferElement>::const_iterator end() const { return m_Elements.end(); }
	private:
		void CalculateStrideAndOffset() 
		{
			uint32_t offset = 0;
			m_Stride = 0;

			for (auto& element : m_Elements)
			{
				element.Offset = offset;
				offset += element.Size;
				m_Stride += element.Size;
			}
		}

	private:
		std::vector<BufferElement> m_Elements;
		uint32_t m_Stride;
	};

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetLayout(const BufferLayout& layout) = 0;
		virtual const BufferLayout& GetLayout() const  = 0;

		static VertexBuffer* Create(float* vertices, uint32_t size);
	};

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual uint32_t GetCount() const = 0;

		static IndexBuffer* Create(uint32_t* indices, uint32_t count);
	};
}