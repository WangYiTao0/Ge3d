#pragma once

#include "Platform/DirectX11/DirectX11Graphics.h"

class DirectX11Graphics;

namespace Ge
{
	class DirectX11GraphicsResource
	{
	protected:
		static ID3D11DeviceContext* GetContext(DirectX11Graphics& gfx) noexcept;
		static ID3D11Device* GetDevice(DirectX11Graphics& gfx) noexcept;
	};
}