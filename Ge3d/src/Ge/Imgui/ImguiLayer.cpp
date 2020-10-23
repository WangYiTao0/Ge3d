#include "ImguiLayer.h"
#include "ge/Renderer/Graphics.h"
#include "Platform/DirectX11/Imgui/DirectX11ImguiLayer.h"
namespace GE
{
	ImGuiLayer* ImGuiLayer::Create()
	{
		switch (Graphics::GetAPI())
		{
			switch (Graphics::GetAPI())
			{
			case API::None:    GE_CORE_ASSERT(false, "API::None is currently not supported!"); return nullptr;
			case API::DirectX11:  return CreateScope<DirectX11Imgui>();
			}
		}
	}
}

