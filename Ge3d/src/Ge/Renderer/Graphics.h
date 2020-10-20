#pragma once
#include "Platform/DirectX11/Debug/Marcros/GrahicsThrowMacro.h"
#include "Platform/DirectX11/Debug/ConditionalNoexcept.h"
#include "Platform/DirectX11/Debug/DxgiInfoManager.h"
#include "Platform/DirectX11/Bindable/Bindable.h"
#include "Platform/DirectX11/Debug/GEException.h"



namespace GE
{
	namespace Bind
	{
		class Bindable;
	}
	enum class API
	{
		None = 0,
		DirectX11 = 1,
		DirectX12 = 2,
		Vulkan = 3,
	};


	class Graphics
	{
	public:
		class Exception :public GEException
		{
			using GEException::GEException;
		};

		class HrException : public Exception
		{
		public:
			HrException(int line, const char* file, HRESULT hr, std::vector<std::string> infoMsgs = {}) noexcept;
			const char* what() const noexcept override;
			const char* GetType() const noexcept override;
			HRESULT GetErrorCode() const noexcept;
			std::string GetErrorString() const noexcept;
			std::string GetErrorDescription() const noexcept;
			std::string GetErrorInfo() const noexcept;
		private:
			HRESULT hr;
			std::string info;
		};
		class DeviceRemovedException : public HrException
		{
			using HrException::HrException;
		public:
			const char* GetType() const noexcept override;
		private:
			std::string reason;
		};

		Graphics() {};
		Graphics(const Graphics&) = delete;
		Graphics& operator=(const Graphics&) = delete;
		virtual ~Graphics() {};
		virtual void BeginFrame(float red, float green, float blue) noexcept = 0;
		virtual void EndFrame() = 0;
		virtual void DrawIndexed(UINT count) noxnd = 0;

		static Scope<Graphics> Create(HWND hwnd);
		static void SetAPI(API api);

		static API GetAPI() { return s_CurrentGraphicsAPI; }
	protected:
#ifndef NDEBUG
		DxgiInfoManager infoManager;
#endif
	private:
		static API s_CurrentGraphicsAPI;

	};
}