#include "gepch.h"
#include "DirectX11Graphics.h"
#include "Ge/Core/Log.h"

namespace Ge
{
	bool DirectX11Graphics::Init(HWND hwnd, UINT width, UINT height)
	{
		HRESULT hr = 0;

		D3D_DRIVER_TYPE driver_types[] = {
			D3D_DRIVER_TYPE_HARDWARE,
			D3D_DRIVER_TYPE_WARP,
			D3D_DRIVER_TYPE_REFERENCE,
		};
		UINT num_driver_types = ARRAYSIZE(driver_types);

		D3D_FEATURE_LEVEL feature_levels[] = {
			D3D_FEATURE_LEVEL_11_0,
		};
		UINT num_feature_levels = ARRAYSIZE(feature_levels);

		for (UINT driver_types_index = 0; driver_types_index < num_driver_types; )
		{
			D3D_FEATURE_LEVEL m_feature_level;
			D3D11CreateDevice(nullptr, driver_types[driver_types_index], nullptr, NULL,
				feature_levels, num_feature_levels, D3D11_SDK_VERSION, m_pd3dDevice.GetAddressOf(),
				&m_feature_level, m_pImmediateContext.GetAddressOf());
			if (SUCCEEDED(hr)) break;
			++driver_types_index;
		}

		if (FAILED(hr)) 
		{ 
			GE_CORE_ERROR("Create d3dDevice Failed");
			return false;
		}

		//create swapchain
		m_pd3dDevice->QueryInterface(__uuidof(IDXGIDevice), (void**)m_pdxgiDevice.GetAddressOf());
		m_pdxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**)m_pdxgiAdapter.GetAddressOf());
		m_pdxgiAdapter->GetParent(__uuidof(IDXGIFactory), (void**)m_pdxgiFactory.GetAddressOf());


		DXGI_SWAP_CHAIN_DESC desc;
		ZeroMemory(&desc, sizeof(desc));
		desc.BufferCount = 1;
		desc.BufferDesc.Width = width;
		desc.BufferDesc.Height = height;
		desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		desc.BufferDesc.RefreshRate.Numerator = 60;
		desc.BufferDesc.RefreshRate.Denominator = 1;
		desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		desc.OutputWindow = hwnd;
		desc.SampleDesc.Count = 1;
		desc.SampleDesc.Quality = 0;
		desc.Windowed = TRUE;

		hr = m_pdxgiFactory->CreateSwapChain(m_pd3dDevice.Get(), &desc, m_pSwapChain.GetAddressOf());

		if (FAILED(hr))
		{
			GE_CORE_ERROR("Create SwapChain Failed");
			return false;
		}

		Microsoft::WRL::ComPtr<ID3D11Texture2D> backbuffer;
		hr = m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D),&backbuffer);
		if (FAILED(hr))
		{
			GE_CORE_ERROR("Get SwapChain backbuffer Failed");
			return false;
		}

		m_pd3dDevice->CreateRenderTargetView(backbuffer.Get(), nullptr, m_pRtv.GetAddressOf());

		if (FAILED(hr))
		{
			GE_CORE_ERROR("Create RenderTargetView Failed");
			return false;
		}

		return true;
	}

	void DirectX11Graphics::BeginFrame()
	{

	}

	void DirectX11Graphics::SetClearColor(float r, float g, float b, float a)
	{
		FLOAT clear_color[] = { r,g,b,a };
		m_pImmediateContext->ClearRenderTargetView(m_pRtv.Get(),clear_color);
	}

	void DirectX11Graphics::SwapBuffers(bool vsync)
	{
		m_pSwapChain->Present(vsync, 0);
	}

	void DirectX11Graphics::OnResize(uint32_t width, uint32_t height)
	{

	}

}

