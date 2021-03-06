#pragma once


namespace Ge {

	class RendererAPI
	{
	public:
		enum class API
		{
			None = 0, 
			OpenGL = 1, 
			DirectX11 = 2, 
			DirectX12 = 3,
		};
	public:
		virtual ~RendererAPI() = default;

		virtual bool Init() = 0;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
		virtual void SetClearColor(float r, float g, float b, float a) = 0;
		virtual void Clear() = 0;

		virtual void DrawIndexed(uint32_t indexCount = 0) = 0;

		static API GetAPI() { return s_API; }
		static Scope<RendererAPI> Create();
	private:
		static API s_API;
	};

}
