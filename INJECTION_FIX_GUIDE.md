# DLL Injection Crash Fix Guide

## Problem
The game crashes when injecting `WeedMen55Cheat (1).dll` using Extreme Injector.

## Common Causes of DLL Injection Crashes

### 1. **DllMain Execution Issues**
The most common cause of DLL injection crashes is when DllMain does too much work during `DLL_PROCESS_ATTACH`:
- Creating threads
- Loading additional DLLs
- Calling functions that acquire locks
- Long-running initialization code
- Calling functions that wait for synchronization objects

**Why this causes crashes:**
- Windows holds the loader lock during DllMain execution
- Many Windows APIs cannot be safely called while holding this lock
- This can cause deadlocks or crashes

### 2. **Missing Dependencies**
If the DLL depends on other DLLs that aren't present in the target process:
- d3d11.dll (DirectX 11) - Check if the game uses DirectX 11
- Other runtime libraries

### 3. **Architecture Mismatch**
The DLL is a 64-bit (PE32+) executable. Ensure:
- The target game is also 64-bit
- Extreme Injector is configured for 64-bit injection

### 4. **Anti-Cheat Detection**
Some games have anti-cheat systems that:
- Detect DLL injection
- Crash the game when unauthorized DLLs are loaded

## Solutions

### Solution 1: Fix DllMain (Requires Source Code)
If you have access to the source code, modify DllMain to follow best practices:

```cpp
// CORRECT: Minimal DllMain
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        // Only disable thread notifications and create a thread for initialization
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, 0, InitThread, hModule, 0, nullptr);
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

// Actual initialization happens in a separate thread
DWORD WINAPI InitThread(LPVOID lpParameter)
{
    // Safe to do heavy work here (loading DLLs, creating hooks, etc.)
    // Add your initialization code here
    
    return 0;
}
```

### Solution 2: Use Manual Mapping
Instead of standard DLL injection, use manual mapping injection:
- Manual mapping bypasses some anti-cheat detection
- Doesn't trigger standard LoadLibrary hooks
- Requires a manual mapping injector instead of Extreme Injector

### Solution 3: Delay Injection
Try injecting the DLL after the game has fully loaded:
1. Launch the game first
2. Wait for it to reach the main menu
3. Then inject the DLL

### Solution 4: Check Extreme Injector Settings
In Extreme Injector, try different injection methods:
- **Standard Injection** (LoadLibrary)
- **LdrLoadDll Injection**
- **Manual Map Injection** (recommended)
- **Thread Hijacking**

Also check:
- ✅ Enable "Scramble DLL Name"
- ✅ Enable "Manual Map"
- ✅ Enable "Close on inject"
- ⬜ Disable "Auto Inject" initially

### Solution 5: Check Game Compatibility
Ensure the DLL is compatible with your game:
- Game must use DirectX 11 (DLL imports d3d11.dll)
- Game must be 64-bit
- Game must not have strong anti-cheat protection

## Debugging Steps

1. **Test with a simple DLL first:**
```cpp
// Simple test DLL
#include <Windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        MessageBoxA(NULL, "DLL Injected Successfully!", "Test", MB_OK);
    }
    return TRUE;
}
```
If this simple DLL works, the problem is in the cheat's DllMain code.

2. **Check Windows Event Viewer:**
- Open Event Viewer (eventvwr.msc)
- Check Windows Logs > Application
- Look for crash reports with details

3. **Use a debugger:**
- Attach x64dbg or WinDbg to the game before injection
- Set breakpoints on DLL loading
- Step through the DllMain execution

## Recommended: Rebuild from Source

The current DLL likely has one or more of these issues. The best solution is to rebuild the DLL with proper injection-safe code.

See `SOURCE_TEMPLATE.cpp` for a proper implementation.
