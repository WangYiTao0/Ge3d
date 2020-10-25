#include "gepch.h"
#include "GraphicsResource.h"


namespace Ge
{

	ID3D11DeviceContext* GraphicsResource::GetContext(DirectX11RendererAPI& renderAPI) noexcept
	{
		return renderAPI.m_pImmediateContext.Get();
	}

	ID3D11Device* GraphicsResource::GetDevice(DirectX11RendererAPI& rederAPI) noexcept
	{
		return rederAPI.m_pd3dDevice.Get();
	}

}
