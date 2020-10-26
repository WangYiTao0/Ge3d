#pragma once
#include "Ge/Renderer/RendererAPI.h"

namespace Ge
{

	class DirectX11RendererAPI : public RendererAPI
	{
	public:
		friend class DirectX11GraphicsResource;
	public:
		virtual bool Init() override;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;

		virtual void SetClearColor(float r,float g, float b, float a) override;
		virtual void Clear() override;

		virtual void DrawIndexed(uint32_t indexCount = 0) override;

	};
}