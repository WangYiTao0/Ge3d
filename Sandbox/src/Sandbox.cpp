#pragma once
#include <Ge3d.h>
#include "Ge/Core/EntryPoint.h"

#include "ExampleLayer.h"

namespace GE
{

	class Sandbox : public Application
	{
	public:
		Sandbox()
		{
			PushLayer(new ExampleLayer());
		}

		~Sandbox()
		{

		}
	};



	Application* CreateApplication()
	{
		return new Sandbox();
	}


}