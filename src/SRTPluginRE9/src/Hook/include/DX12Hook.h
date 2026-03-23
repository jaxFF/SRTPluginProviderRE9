#ifndef SRTPLUGINRE9_DX12HOOK_H
#define SRTPLUGINRE9_DX12HOOK_H

#include <d3d12.h>
#include <dxgi.h>
#include <dxgi1_4.h>

namespace SRTPluginRE9::DX12Hook
{
	/// @brief A hook class wrapping DX12 resources.
	class DX12Hook
	{
	private:
		DX12Hook(); // Resolve and store DX12 VTables.

		// Function pointer definitions.
		using PFN_Present = HRESULT(STDMETHODCALLTYPE *)(IDXGISwapChain3 *, UINT, UINT);
		using PFN_ResizeBuffers = HRESULT(STDMETHODCALLTYPE *)(IDXGISwapChain *, UINT, UINT, UINT, DXGI_FORMAT, UINT);
		using PFN_ExecuteCommandLists = void(STDMETHODCALLTYPE *)(ID3D12CommandQueue *, UINT, ID3D12CommandList *const *);

		// Original function pointers (set by MinHook)
		PFN_Present oPresent = nullptr;
		PFN_ResizeBuffers oResizeBuffers = nullptr;
		PFN_ExecuteCommandLists oExecuteCommandLists = nullptr;

		struct DX12VTableAddresses
		{
			void *present;
			void *resizeBuffers;
			void *executeCommandLists;
		};

	public:
		// Deleted methods (only allow default ctor/dtor, move ctor, and move assignment)
		// DX12Hook(void) = delete;                        // default ctor (1)
		// ~DX12Hook(void) = delete;                       // default dtor (2)
		DX12Hook(const DX12Hook &) = delete; // copy ctor (3)
		// DX12Hook(const DX12Hook &&) = delete;            // move ctor (4)
		DX12Hook &operator=(const DX12Hook &) = delete; // copy assignment (5)
		                                                // DX12Hook &operator=(const DX12Hook &&) = delete; // move assignment (6)

		/// @brief Get the singleton instance of this class.
		/// @return The singleton instance of this class.
		static DX12Hook &GetInstance();

		/// @brief Attach hooks and create resources.
		/// @return The last HRESULT operation.
		HRESULT STDMETHODCALLTYPE Initialize();

		/// @brief Detach hooks and release resources.
		/// @return The last HRESULT operation.
		HRESULT STDMETHODCALLTYPE Release();
	};
}

#endif
