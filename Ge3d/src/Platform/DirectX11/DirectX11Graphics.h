#pragma once
#include "GE/Renderer/Graphics.h"

namespace GE
{
	class DirectX11Graphics : public Graphics
	{

	public:
		DirectX11Graphics(HWND hWnd, int width = 1600, int height = 900);
		virtual void BeginFrame(float red, float green, float blue) noexcept override;
		virtual void EndFrame() override;

	private:
		UINT width;
		UINT height;
		Microsoft::WRL::ComPtr<ID3D11Device> m_pDevice;
		Microsoft::WRL::ComPtr<IDXGISwapChain> m_pSwap;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_pContext;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_pTarget;
	};

}