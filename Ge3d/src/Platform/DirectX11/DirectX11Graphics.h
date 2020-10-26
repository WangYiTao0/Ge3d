#pragma once

#include "Ge/Renderer/Graphics.h"

namespace Ge
{
	class DirectX11Graphics : public Graphics
	{
	public:
		friend class DirectX11GraphicsResource;
	public:

		virtual bool Init(HWND hwnd, UINT width, UINT height) override;

		virtual void BeginFrame() override;

		virtual void SetClearColor(float r, float g, float b, float a) override;
	
		virtual void SwapBuffers(bool vsync) override;

		virtual void OnResize(uint32_t width, uint32_t height) override;

	private:


	private:
		Microsoft::WRL::ComPtr<ID3D11Device> m_pd3dDevice;
		Microsoft::WRL::ComPtr<IDXGISwapChain> m_pSwapChain;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_pImmediateContext;

		D3D_FEATURE_LEVEL m_feature_level;

		Microsoft::WRL::ComPtr<IDXGIDevice> m_pdxgiDevice;
		Microsoft::WRL::ComPtr<IDXGIAdapter> m_pdxgiAdapter;
		Microsoft::WRL::ComPtr<IDXGIFactory> m_pdxgiFactory;

		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_pRtv;
		
	};
}