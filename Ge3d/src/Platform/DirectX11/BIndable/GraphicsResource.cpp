#include "gepch.h"
#include "GraphicsResource.h"


namespace Ge
{

	ID3D11DeviceContext* GraphicsResource::GetContext(DirectX11Context& directX11Context) noexcept
	{
		return directX11Context.m_pImmediateContext.Get();
	}

	ID3D11Device* GraphicsResource::GetDevice(DirectX11Context& directX11Context) noexcept
	{
		return directX11Context.m_pd3dDevice.Get();
	}

}
