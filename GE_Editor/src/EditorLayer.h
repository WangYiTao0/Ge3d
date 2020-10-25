#pragma once

#include <Ge3d.h>

namespace Ge {

	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(float dt) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event& e) override;
	private:

	};

}
