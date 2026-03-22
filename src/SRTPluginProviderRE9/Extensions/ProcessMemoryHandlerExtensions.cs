using System;
using ProcessMemory;

namespace SRTPluginProviderRE9.Extensions;

internal static unsafe class ProcessMemoryHandlerExtensions
{
    internal static unsafe T DerefChain<T>(this ProcessMemoryHandler processMemoryHandler, IntPtr baseAddress, params int[] offsets) where T : unmanaged
    {
        for (var i = 0; i < offsets.Length - 1; ++i)
            baseAddress = processMemoryHandler.GetNIntAt(IntPtr.Add(baseAddress, offsets[i]).ToPointer());
        return processMemoryHandler.GetAt<T>(IntPtr.Add(baseAddress, offsets[offsets.Length - 1]).ToPointer());
    }
}
