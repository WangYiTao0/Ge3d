#pragma once

#include "Platform/DirectX11/DirectX11RendererAPI.h"

class DirectX11RendererAPI;

namespace Ge
{
	class GraphicsResource
	{
	protected:
		static ID3D11DeviceContext* GetContext(DirectX11RendererAPI& gfx) noexcept;
		static ID3D11Device* GetDevice(DirectX11RendererAPI& gfx) noexcept;
	};
}