#pragma once

#include "Ge/Core/Layer.h"

namespace GE
{
	class ImGuiLayer : public Layer
	{
	public:
		virtual void Begin() = 0;
		virtual void End() = 0;

		static ImGuiLayer* Create();
	};
}