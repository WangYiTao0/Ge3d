#include <Ge3d.h>
#include "ExampleLayer.h"

namespace GE
{
	ExampleLayer::ExampleLayer()
		: Layer("Example")
	{
	}
	void ExampleLayer::OnUpdate(float dt)
	{
		//GE_INFO("ExampleLayer::Update");

		if (GE::Input::IsKeyPressed(GE_TAB))
			GE_INFO("Tab key is pressed");
	}
	void ExampleLayer::OnEvent(GE::Event& e)
	{
		GE_TRACE("{0}", e);
	}
}