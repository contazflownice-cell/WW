/*
 * DLL Injection Safe Template
 * 
 * This template demonstrates the correct way to implement a DLL
 * for injection into games, avoiding common crashes.
 * 
 * Key principles:
 * 1. DllMain must be minimal and fast
 * 2. All heavy initialization happens in a separate thread
 * 3. No loader-locked functions are called during DLL_PROCESS_ATTACH
 */

#include <Windows.h>
#include <d3d11.h>
#include <thread>

// Global variables
HMODULE g_hModule = NULL;
bool g_bRunning = true;

// Forward declarations
DWORD WINAPI MainThread(LPVOID lpParameter);
void InitializeCheat();
void ShutdownCheat();

/*
 * DllMain - The entry point of the DLL
 * 
 * CRITICAL: Keep this function minimal!
 * - Do NOT load additional DLLs here
 * - Do NOT create synchronization objects
 * - Do NOT call functions that acquire locks
 * - Do NOT perform lengthy operations
 */
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        // Store module handle
        g_hModule = hModule;
        
        // Disable thread attach/detach notifications (optimization)
        DisableThreadLibraryCalls(hModule);
        
        // Create a thread for actual initialization
        // This is safe because CreateThread doesn't hold the loader lock
        HANDLE hThread = CreateThread(
            nullptr,           // Default security attributes
            0,                 // Default stack size
            MainThread,        // Thread function
            hModule,           // Parameter to pass to thread
            0,                 // Start immediately
            nullptr            // Don't need thread ID
        );
        
        // Close the thread handle (thread continues to run)
        if (hThread)
        {
            CloseHandle(hThread);
        }
        break;
        
    case DLL_PROCESS_DETACH:
        // Signal shutdown
        g_bRunning = false;
        break;
        
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        // We disabled these with DisableThreadLibraryCalls
        break;
    }
    
    return TRUE;
}

/*
 * MainThread - The main initialization thread
 * 
 * This is where all the actual initialization happens.
 * It's safe to do anything here because we're not holding the loader lock.
 */
DWORD WINAPI MainThread(LPVOID lpParameter)
{
    try
    {
        // Optional: Wait a bit for the game to fully initialize
        // This can help with some games that need more time to load
        Sleep(1000);
        
        // Now it's safe to initialize everything
        InitializeCheat();
        
        // Main loop (if needed)
        while (g_bRunning)
        {
            // Your main cheat loop here
            // Example: Update ESP, aimbot, etc.
            
            // Sleep to avoid consuming too much CPU
            Sleep(10);
        }
        
        // Cleanup
        ShutdownCheat();
        
        // Optional: Eject the DLL
        // FreeLibraryAndExitThread((HMODULE)lpParameter, 0);
    }
    catch (...)
    {
        // Handle any exceptions
        MessageBoxA(NULL, "Error in MainThread", "Error", MB_OK | MB_ICONERROR);
    }
    
    return 0;
}

/*
 * InitializeCheat - Initialize all cheat features
 * 
 * This function is called from MainThread, so it's safe to:
 * - Load additional DLLs
 * - Create hooks
 * - Initialize graphics
 * - Allocate memory
 * - Create additional threads
 */
void InitializeCheat()
{
    // Example initialization code
    
    // 1. Setup console for debugging (optional)
    #ifdef _DEBUG
    AllocConsole();
    FILE* pFile;
    freopen_s(&pFile, "CONOUT$", "w", stdout);
    printf("Cheat initialized!\n");
    #endif
    
    // 2. Get game modules
    // HMODULE hGameModule = GetModuleHandleA("game.exe");
    
    // 3. Find game functions/addresses
    // You might use pattern scanning here
    
    // 4. Setup hooks (e.g., DirectX hooks)
    // Example for D3D11:
    /*
    IDXGISwapChain* pSwapChain = nullptr;
    ID3D11Device* pDevice = nullptr;
    ID3D11DeviceContext* pContext = nullptr;
    
    // Get swap chain, device, and context
    // Then hook Present, etc.
    */
    
    // 5. Initialize features
    // - ESP
    // - Aimbot
    // - Wallhack
    // - etc.
    
    // Success message (optional, remove for stealth)
    // MessageBoxA(NULL, "Cheat loaded successfully!", "Success", MB_OK);
}

/*
 * ShutdownCheat - Cleanup before unloading
 * 
 * This function is called before the DLL is unloaded.
 * Make sure to cleanup all resources:
 * - Remove hooks
 * - Free allocated memory
 * - Close handles
 */
void ShutdownCheat()
{
    // 1. Remove all hooks
    // DetourDetach, etc.
    
    // 2. Free allocated memory
    
    // 3. Close handles
    
    // 4. Cleanup console (if created)
    #ifdef _DEBUG
    fclose(stdout);
    FreeConsole();
    #endif
}

/*
 * Example: DirectX 11 Hook Setup
 * 
 * If your cheat needs to hook DirectX 11 (for ESP, etc.),
 * here's an example of how to do it safely:
 */

// Example hook function (you'll need a hooking library like MinHook or Detours)
/*
typedef HRESULT(__stdcall* Present_t)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
Present_t oPresent = nullptr;

HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
    // Your rendering code here
    // Example: Draw ESP, menu, etc.
    
    // Call original function
    return oPresent(pSwapChain, SyncInterval, Flags);
}

void SetupD3D11Hooks()
{
    // Get D3D11 device and swap chain
    // Then hook the Present function
    // This is just pseudocode - you'll need a proper hooking library
    
    // MinHook example:
    // MH_Initialize();
    // MH_CreateHook(PresentAddress, &hkPresent, reinterpret_cast<LPVOID*>(&oPresent));
    // MH_EnableHook(PresentAddress);
}
*/

/*
 * Compilation Instructions:
 * 
 * Using Visual Studio:
 * 1. Create a new "Dynamic-Link Library (DLL)" project
 * 2. Set platform to x64 (for 64-bit games) or x86 (for 32-bit games)
 * 3. Copy this code into the main .cpp file
 * 4. Add necessary libraries:
 *    - d3d11.lib (if using DirectX)
 *    - Any hooking library (MinHook, Detours, etc.)
 * 5. Build in Release mode for production
 * 
 * Compiler Settings:
 * - Configuration Type: Dynamic Library (.dll)
 * - Platform Toolset: Latest (v143)
 * - C++ Language Standard: C++17 or later
 * - Runtime Library: Multi-threaded (/MT) for Release
 * 
 * Using CMake:
 * cmake_minimum_required(VERSION 3.10)
 * project(MyCheat)
 * 
 * add_library(MyCheat SHARED SOURCE_TEMPLATE.cpp)
 * target_link_libraries(MyCheat d3d11)
 * set_target_properties(MyCheat PROPERTIES
 *     CXX_STANDARD 17
 *     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
 * )
 */
