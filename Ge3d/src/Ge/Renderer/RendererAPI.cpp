#include "gepch.h"
#include "RendererAPI.h"

#include "Platform/DirectX11/DirectX11RendererAPI.h"

namespace GE
{

	GE::Scope<GE::RendererAPI> RendererAPI::create()
	{
		switch (s_API)
		{
		case RendererAPI::API_Type::None:    GE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API_Type::OpenGL:  return CreateScope<DirectXRendererAPI>();
		}
	}

	//RendererAPI::API_Type RendererAPI::s_API = RendererAPI::API_Type::DirectX11;
}


