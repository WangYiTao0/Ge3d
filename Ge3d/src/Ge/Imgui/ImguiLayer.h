#pragma once

#include "Ge/Core/Layer.h"

namespace Ge
{
	class ImGuiLayer : public Layer
	{
	public:
		virtual void Begin() = 0;
		virtual void End() = 0;

		static ImGuiLayer* Create();
	};
}