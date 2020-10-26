#pragma once

namespace Ge
{
	class GraphicsContext
	{
	public: 
		GraphicsContext() = default;
		virtual~GraphicsContext() = default;


		virtual bool Init(HWND hwnd, UINT width, UINT height) = 0;
		virtual void BeginFrame() = 0;
		virtual void SetClearColor(float r, float g, float b, float a) = 0;
		virtual void SwapBuffers(bool vsync) = 0;
		virtual void OnResize(uint32_t width, uint32_t height) = 0;

		static Scope<GraphicsContext> Create();
	};
}