#pragma once
#include <Ge3d.h>

namespace Ge
{
	class ExampleLayer : public Layer
	{
	public:
		ExampleLayer();

		void OnUpdate(float dt) override;

		void OnEvent(Ge::Event& e) override;
	};
}