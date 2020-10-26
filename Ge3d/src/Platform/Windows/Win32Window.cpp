#include "gepch.h"
#include "Win32Window.h"

#include "GE/Events/ApplicationEvent.h"
#include "GE/Events/KeyEvent.h"
#include "GE/Events/MouseEvent.h"


#include <imgui_impl_win32.h>

IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


namespace Ge
{
	static bool sWin32Initialized = false;


	HINSTANCE hInstance;

	static void Win32ErrorCallback(int error, const char* description)
	{
		GE_CORE_ERROR("Win32 Error ({0}): {1}", error, description);
	}


	Win32Window::Win32Window(const WindowProps& props)
	{
		Init(props);
	}

	Win32Window::~Win32Window()
	{
		Shutdown();
	}

	void Win32Window::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		GE_CORE_INFO("Creating window {0} {1} {2}", props.Title, props.Width, props.Height);

		hInstance = GetModuleHandle(0);

		WNDCLASSEX wc = {};
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_OWNDC;
		wc.lpfnWndProc = WindowProc;
		wc.hInstance = hInstance;
		wc.lpszClassName = "GE Win32 Window";
		wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		wc.hIconSm = wc.hIcon;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = sizeof(WindowData*);
		wc.lpszMenuName = NULL;

		if (!RegisterClassEx(&wc))
		{
			GE_CORE_ERROR("Could not initialize the window class!");
		}

		// calculate window size based on desired client region size
		RECT wr;
		wr.left = 100;
		wr.right = m_Data.Width + wr.left;
		wr.top = 100;
		wr.bottom = m_Data.Height + wr.top;
		AdjustWindowRect(&wr, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, FALSE);

		//m_Win32Window = CreateWindowEx(0, wc.lpszClassName, m_Data.Title.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, m_Data.Width, m_Data.Height, NULL, NULL, hInstance, NULL);
		m_Win32Window = CreateWindow(
			wc.lpszClassName, m_Data.Title.c_str(),
			WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
			CW_USEDEFAULT, CW_USEDEFAULT, wr.right - wr.left, wr.bottom - wr.top,
			nullptr, nullptr, hInstance, this
		);

		if (!sWin32Initialized)
		{
			GE_CORE_ASSERT(m_Win32Window, "Could not initialize Win32!");

			sWin32Initialized = true;
		}

		SetWindowLongPtr(m_Win32Window, 0, (LONG_PTR)&m_Data);
		ShowWindow(m_Win32Window, SW_SHOW);
		UpdateWindow(m_Win32Window);
		SetFocus(m_Win32Window);

		m_Context = GraphicsContext::Create();
		m_Context->Init(m_Win32Window,m_Data.Width,m_Data.Height);

	}

	void Win32Window::Shutdown()
	{
		DestroyWindow(m_Win32Window);
	}

	void Win32Window::OnUpdate()
	{

		MSG message;

		while (PeekMessage(&message, NULL, 0, 0, PM_REMOVE) > 0)
		{
			TranslateMessage(&message);
			DispatchMessage(&message);

		}

		m_Context->SetClearColor(1.0, 0.0, 0.0, 1.0);
		m_Context->SwapBuffers(m_Data.VSync);
	}

	void Win32Window::SetVSync(bool enabled)
	{
		m_Data.VSync = enabled;
	}

	bool Win32Window::IsVSync() const
	{
		return m_Data.VSync;
	}

	LRESULT CALLBACK Win32Window::WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
	{
		LRESULT result = NULL;

		if (ImGui_ImplWin32_WndProcHandler(hWnd, uMessage, wParam, lParam))
			return true;

		switch (uMessage)
		{
		case WM_SIZING:
		{
			RECT rect = *((PRECT)lParam);

			WindowData* data = (WindowData*)GetWindowLongPtr(hWnd, 0);
			WindowResizeEvent event((unsigned int)(rect.right - rect.left), (unsigned int)(rect.bottom - rect.top));
			data->EventCallback(event);
			break;
		}
		case WM_CLOSE:
		case WM_DESTROY:
		{
			WindowData* data = (WindowData*)GetWindowLongPtr(hWnd, 0);

			WindowCloseEvent event;
			data->EventCallback(event);
			break;
		}
		case WM_KEYUP:
		{
			WindowData* data = (WindowData*)GetWindowLongPtr(hWnd, 0);

			KeyReleasedEvent event(static_cast<int>(wParam));
			data->EventCallback(event);
			break;
		}
		case WM_KEYDOWN:
		{
			WindowData* data = (WindowData*)GetWindowLongPtr(hWnd, 0);
			int repeatCount = (lParam & 0xffff);

			KeyPressedEvent event(static_cast<int>(wParam), repeatCount);
			data->EventCallback(event);
			break;
		}
		case WM_MOUSEMOVE:
		{
			WindowData* data = (WindowData*)GetWindowLongPtr(hWnd, 0);

			MouseMovedEvent event((float)GET_X_LPARAM(lParam), (float)GET_Y_LPARAM(lParam));
			data->EventCallback(event);
			break;
		}
		case WM_MOUSEWHEEL:
		{
			WindowData* data = (WindowData*)GetWindowLongPtr(hWnd, 0);

			MouseScrolledEvent event(GET_WHEEL_DELTA_WPARAM(wParam));
			data->EventCallback(event);
			break;
		}
		case WM_LBUTTONDOWN:
		{
			WindowData* data = (WindowData*)GetWindowLongPtr(hWnd, 0);

			MouseButtonPressedEvent event(MK_LBUTTON);
			data->EventCallback(event);
			break;
		}
		case WM_LBUTTONUP:
		{
			WindowData* data = (WindowData*)GetWindowLongPtr(hWnd, 0);

			MouseButtonReleasedEvent event(MK_LBUTTON);
			data->EventCallback(event);
			break;
		}
		case WM_MBUTTONDOWN:
		{
			WindowData* data = (WindowData*)GetWindowLongPtr(hWnd, 0);

			MouseButtonPressedEvent event(MK_MBUTTON);
			data->EventCallback(event);
			break;
		}
		case WM_MBUTTONUP:
		{
			WindowData* data = (WindowData*)GetWindowLongPtr(hWnd, 0);

			MouseButtonReleasedEvent event(MK_MBUTTON);
			data->EventCallback(event);
			break;
		}
		case WM_RBUTTONDOWN:
		{
			WindowData* data = (WindowData*)GetWindowLongPtr(hWnd, 0);

			MouseButtonPressedEvent event(MK_RBUTTON);
			data->EventCallback(event);
			break;
		}
		case WM_RBUTTONUP:
		{
			WindowData* data = (WindowData*)GetWindowLongPtr(hWnd, 0);

			MouseButtonReleasedEvent event(MK_RBUTTON);
			data->EventCallback(event);
			break;
		}
		default:
			result = DefWindowProc(hWnd, uMessage, wParam, lParam);
		}

		return result;
	}


}