#pragma once

#include "GE/Imgui/ImguiLayer.h"

#include "GE/Events/ApplicationEvent.h"
#include "GE/Events/KeyEvent.h"
#include "GE/Events/MouseEvent.h"

namespace Ge {

	class DirectX11ImGuiLayer : public ImGuiLayer
	{
	public:
		DirectX11ImGuiLayer();
		DirectX11ImGuiLayer(const std::string& name);
		~DirectX11ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { mBlockEvents = block; }
		void SetDarkThemeColors();
	private:

		bool mBlockEvents = true;
	};

}