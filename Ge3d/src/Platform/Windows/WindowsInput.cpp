#include "gepch.h"
#include "WindowsInput.h"

#include "GE/Core/Application.h"

#include <Windows.h>

namespace Ge {


	bool WindowsInput::IsKeyPressedImpl(int key)
	{
		auto state = GetAsyncKeyState(key);

		return (state & 0x8000);
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		auto state = GetAsyncKeyState(button);

		return (state & 0x8000);
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		POINT p;

		GetCursorPos(&p);

		return { (float)p.x, (float)p.y };
	}

	float WindowsInput::GetMouseXImpl()
	{
		auto [x, y] = GetMousePositionImpl();

		return x;
	}

	float WindowsInput::GetMouseYImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return y;
	}

}