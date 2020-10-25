#include "gepch.h"
#include "DirectX11RendererAPI.h"


namespace Ge
{

	bool DirectX11RendererAPI::Init()
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

		if (FAILED(hr)) return false;

		return true;
	}

	void DirectX11RendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{

	}

	void DirectX11RendererAPI::SetClearColor(float r, float g, float b, float a)
	{

	}

	void DirectX11RendererAPI::Clear()
	{

	}

	void DirectX11RendererAPI::DrawIndexed(uint32_t indexCount /*= 0*/)
	{

	}

}