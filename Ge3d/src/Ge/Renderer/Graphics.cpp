#include "gepch.h"
#include "Graphics.h"

#include "Ge/Renderer/RendererAPI.h"


#include "Platform/DirectX11/DirectX11Graphics.h"


namespace Ge {

	Scope<Graphics> Graphics::Create()
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:    GE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::DirectX11:  return CreateScope<DirectX11Graphics>();
		}

		GE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}