#include "gepch.h"
#include "Window.h"

#ifdef GE_PLATFORM_WINDOWS
//#include "Platform/Windows/OpenGLWindow.h"
#include "Platform/Windows/Win32Window.h"
#endif

namespace Ge
{

	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef GE_PLATFORM_WINDOWS
		return CreateScope<Win32Window>(props);
#else
		GE_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}

