#pragma once
#include "Base.h"

#include "Window.h"
#include "LayerStack.h"
#include "GE/Events/Event.h"
#include "GE/Events/ApplicationEvent.h"

#include "GE/ImGui/ImGuiLayer.h"

#include "Ge/Renderer/GraphicsContext.h"

int main(int argc, char** argv);

namespace Ge
{
	class  Application
	{
	public:
		Application(const std::string& name = "Ge App");
		virtual ~Application();


		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;


		float m_LastFrameTime = 0.0f;

	private:
		static Application* s_Instance;
		Timer timer;
		float speed_factor = 1.0f;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}