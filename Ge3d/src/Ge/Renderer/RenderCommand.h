#pragma once

#include "Ge/Renderer/RendererAPI.h"

namespace Ge {

	class RenderCommand
	{
	public:
		static void Init()
		{
			s_RendererAPI->Init();
		}

		static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
		{
			s_RendererAPI->SetViewport(x, y, width, height);
		}

		static void SetClearColor(float r, float g, float b, float a)
		{
			s_RendererAPI->SetClearColor(r,g,b,a);
		}

		static void Clear()
		{
			s_RendererAPI->Clear();
		}

		static void DrawIndexed(uint32_t count = 0)
		{
			s_RendererAPI->DrawIndexed(count);
		}
	private:
		static Scope<RendererAPI> s_RendererAPI;
	};

}
#pragma once
