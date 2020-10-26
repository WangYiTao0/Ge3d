#include "gepch.h"
#include "GraphicsResource.h"


namespace Ge
{

	ID3D11DeviceContext* DirectX11GraphicsResource::GetContext(DirectX11Graphics& gfx) noexcept
	{
		return gfx.m_pImmediateContext.Get();
	}

	ID3D11Device* DirectX11GraphicsResource::GetDevice(DirectX11Graphics& gfx) noexcept
	{
		return gfx.m_pd3dDevice.Get();
	}

}
