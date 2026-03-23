#include "DX12Hook.h"

namespace SRTPluginRE9::DX12Hook
{
	DX12Hook::DX12Hook() // Resolve and store DX12 VTables.
	{
	}

	DX12Hook &DX12Hook::GetInstance() // Return the singleton instance of this class.
	{
		static DX12Hook instance;
		return instance;
	}

	HRESULT STDMETHODCALLTYPE DX12Hook::Initialize() // Attach hooks and create resources.
	{
		return S_OK;
	}

	HRESULT STDMETHODCALLTYPE DX12Hook::Release() // Detach hooks and release resources.
	{
		return S_OK;
	}
}
