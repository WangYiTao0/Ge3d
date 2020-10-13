#include "gepch.h"
#include "Window.h"
#include "GE/Core/Input.h"

#ifdef GE_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsInput.h"
#endif

namespace GE {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
#ifdef GE_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
#else
		GE_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}