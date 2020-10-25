#pragma once
#include "Ge/Renderer/RendererAPI.h"

namespace Ge
{

	class DirectX11RendererAPI : public RendererAPI
	{
	public:
		friend class GraphicsResource;
	public:
		virtual bool Init() override;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;

		virtual void SetClearColor(float r,float g, float b, float a) override;
		virtual void Clear() override;

		virtual void DrawIndexed(uint32_t indexCount = 0) override;

	public:

	private:
		Microsoft::WRL::ComPtr<ID3D11Device> m_pd3dDevice;
		Microsoft::WRL::ComPtr<IDXGISwapChain> pSwap;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_pImmediateContext;

		D3D_FEATURE_LEVEL m_feature_level;
	};
}