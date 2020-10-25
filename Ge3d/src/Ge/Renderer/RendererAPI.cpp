#include "gepch.h"
#include "Ge/Renderer/RendererAPI.h"

#include "Platform/DirectX11/DirectX11RendererAPI.h"

namespace Ge {

	RendererAPI::API RendererAPI::s_API = RendererAPI::API::DirectX11;

	Scope<RendererAPI> RendererAPI::Create()
	{
		switch (s_API)
		{
		case RendererAPI::API::None:    GE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::DirectX11:  return CreateScope<DirectX11RendererAPI>();
		}

		GE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}