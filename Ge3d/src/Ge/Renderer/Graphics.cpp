#include "gepch.h"
#include "Graphics.h"
#include "Platform/DirectX11/Debug/Dxerr/dxerr.h"

#include "Platform/DirectX11/DirectX11Graphics.h"

namespace GE
{
	namespace wrl = Microsoft::WRL;

	API Graphics::s_CurrentGraphicsAPI = API::DirectX11;


	GE::Scope<GE::Graphics> Graphics::Create(HWND hwnd)
	{
		switch (Graphics::GetAPI())
		{
		case API::None:    GE_CORE_ASSERT(false, "API::None is currently not supported!"); return nullptr;
		case API::DirectX11:  return CreateScope<DirectX11Graphics>(hwnd);
		}
	}

	void Graphics::SetAPI(API api)
	{
		s_CurrentGraphicsAPI = api;
	}

	Graphics::HrException::HrException(int line, const char* file, HRESULT hr, std::vector<std::string> infoMsgs) noexcept
		:
		Exception(line, file),
		hr(hr)
	{
		// join all info messages with newlines into single string
		for (const auto& m : infoMsgs)
		{
			info += m;
			info.push_back('\n');
		}
		// remove final newline if exists
		if (!info.empty())
		{
			info.pop_back();
		}
	}

	const char* Graphics::HrException::what() const noexcept
	{
		std::ostringstream oss;
		oss << GetType() << std::endl
			<< "[Error Code] 0x" << std::hex << std::uppercase << GetErrorCode()
			<< std::dec << " (" << (unsigned long)GetErrorCode() << ")" << std::endl
			<< "[Error String] " << GetErrorString() << std::endl
			<< "[Description] " << GetErrorDescription() << std::endl;
		if (!info.empty())
		{
			oss << "\n[Error Info]\n" << GetErrorInfo() << std::endl << std::endl;
		}
		oss << GetOriginString();
		whatBuffer = oss.str();
		return whatBuffer.c_str();
	}

	const char* Graphics::HrException::GetType() const noexcept
	{
		return "JF Graphics Exception";
	}

	HRESULT Graphics::HrException::GetErrorCode() const noexcept
	{
		return hr;
	}

	std::string Graphics::HrException::GetErrorString() const noexcept
	{
		return DXGetErrorString(hr);
	}

	std::string Graphics::HrException::GetErrorDescription() const noexcept
	{
		char buf[512];
		DXGetErrorDescription(hr, buf, sizeof(buf));
		return buf;
	}

	std::string Graphics::HrException::GetErrorInfo() const noexcept
	{
		return info;
	}

	const char* Graphics::DeviceRemovedException::GetType() const noexcept
	{
		return "JF Graphics Exception [Device Removed] (DXGI_ERROR_DEVICE_REMOVED)";
	}



}


