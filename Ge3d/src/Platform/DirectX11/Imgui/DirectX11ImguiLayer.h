#pragma once

#include "GE/Core/Layer.h"

#include "GE/Events/ApplicationEvent.h"
#include "GE/Events/KeyEvent.h"
#include "GE/Events/MouseEvent.h"

namespace GE {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate(float dt) override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();
	private:
		bool OnWindowResizeEvent(WindowResizeEvent& e);
	};

}