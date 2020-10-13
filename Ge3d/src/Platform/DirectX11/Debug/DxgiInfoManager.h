#pragma once
#include <wrl.h>
#include <vector>
#include <dxgidebug.h>

namespace GE
{

	class DxgiInfoManager
	{
	public:
		DxgiInfoManager();
		~DxgiInfoManager() = default;
		DxgiInfoManager(const DxgiInfoManager&) = delete;
		DxgiInfoManager& operator=(const DxgiInfoManager&) = delete;
		void Set() noexcept;
		std::vector<std::string> GetMessages() const;
	private:
		unsigned long long next = 0u;
		Microsoft::WRL::ComPtr<IDXGIInfoQueue> pDxgiInfoQueue;
	};
}