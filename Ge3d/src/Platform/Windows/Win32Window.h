#include "GE/Core/Window.h"
#include "Ge/Renderer/Graphics.h"

#include <d3d11.h>

namespace GE
{
	class Win32Window : public Window
	{
	public:
		class Exception : public GEException
		{
			using GEException::GEException;
		public:
			static std::string TranslateErrorCode(HRESULT hr) noexcept;
		};

		class HrException : public Exception
		{
		public:
			HrException(int line, const char* file, HRESULT hr) noexcept;
			const char* what() const noexcept override;
			const char* GetType() const noexcept override;
			HRESULT GetErrorCode() const noexcept;
			std::string GetErrorDescription() const noexcept;
		private:
			HRESULT hr;
		};

		class NoGfxException : public Exception
		{
		public:
			using Exception::Exception;
			const char* GetType() const noexcept override;
		};

	public:
		Win32Window(const WindowProps& props);
		virtual ~Win32Window();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		// Window attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline virtual HWND GetNativeWindow() const { return m_Win32Window; }

		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

		Graphics& Gfx();
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:

		HWND m_Win32Window;
		Scope<Graphics> pGfx;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}