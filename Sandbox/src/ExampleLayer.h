#pragma once
#include <Ge3d.h>

namespace GE
{
	class ExampleLayer : public Layer
	{
	public:
		ExampleLayer();

		void OnUpdate(float dt) override;

		void OnEvent(GE::Event& e) override;
	};
}