#include <Ge3d.h>
#include <Ge/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Ge {

	class JFEditor : public Application
	{
	public:
		JFEditor()
			: Application("JF Editor")
		{
			PushLayer(new EditorLayer());
		}

		~JFEditor()
		{
		}
	};

	Application* CreateApplication()
	{
		return new JFEditor();
	}

}