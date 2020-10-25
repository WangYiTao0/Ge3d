#include "gepch.h"
#include "Platform/DirectX11/DirectX11ImguiLayer.h"

#include "imgui.h"

#include "GE/Core/Application.h"
#include "GE/Core/KeyCodes.h"

#include <d3d11.h>

#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>

namespace Ge
{

	DirectX11ImGuiLayer::DirectX11ImGuiLayer()
	{

	}

	DirectX11ImGuiLayer::DirectX11ImGuiLayer(const std::string& name)
	{

	}

	DirectX11ImGuiLayer::~DirectX11ImGuiLayer()
	{

	}

	void DirectX11ImGuiLayer::OnAttach()
	{
		GE_PROFILE_FUNCTION();

		ImGui_ImplWin32_EnableDpiAwareness();

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

		io.ConfigFlags |= ImGuiConfigFlags_DpiEnableScaleFonts;
		io.ConfigFlags |= ImGuiConfigFlags_DpiEnableScaleViewports;

	}

	void DirectX11ImGuiLayer::OnDetach()
	{

	}

	void DirectX11ImGuiLayer::OnEvent(Event& e)
	{

	}

	void DirectX11ImGuiLayer::Begin()
	{

	}

	void DirectX11ImGuiLayer::End()
	{

	}

	void DirectX11ImGuiLayer::SetDarkThemeColors()
	{

	}

}