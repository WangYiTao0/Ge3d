#include "gepch.h"
#include "ImguiLayer.h"
#include "ge/Renderer/RendererAPI.h"
#include "Platform/DirectX11/DirectX11ImguiLayer.h"
namespace Ge
{
	ImGuiLayer* ImGuiLayer::Create()
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:   
			GE_CORE_ASSERT(false, "API::None is currently not supported!");
			return nullptr;
		case RendererAPI::API::DirectX11:  return new DirectX11ImGuiLayer();
		}
	}
}

