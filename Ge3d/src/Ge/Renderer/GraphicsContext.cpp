#include "gepch.h"
#include "GraphicsContext.h"

#include "Ge/Renderer/RendererAPI.h"


#include "Platform/DirectX11/DirectX11Context.h"


namespace Ge {

	Scope<GraphicsContext> GraphicsContext::Create()
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:    GE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::DirectX11:  return CreateScope<DirectX11Context>();
		}

		GE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}