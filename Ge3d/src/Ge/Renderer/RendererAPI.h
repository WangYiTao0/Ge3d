#pragma once

namespace GE
{
	class RendererAPI
	{
	public:
		enum class API_Type
		{
			None = 0,
			OpenGL = 1,
			DirectX11 = 2,
			DirectX12 = 3,
			Vulkan = 4,
		};

	public: 
		virtual ~RendererAPI() = default;

		static API_Type GetAPI() { return s_API; }
		static Scope<RendererAPI> create();
	private:
		static API_Type s_API;
	};
}