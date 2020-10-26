#pragma once

#include "Platform/DirectX11/DirectX11Context.h"

class DirectX11RendererAPI;

namespace Ge
{
	class GraphicsResource
	{
	protected:
		static ID3D11DeviceContext* GetContext(DirectX11Context& directX11Context) noexcept;
		static ID3D11Device* GetDevice(DirectX11Context& directX11Context) noexcept;
	};
}