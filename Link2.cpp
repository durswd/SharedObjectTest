#include "DynamicLinkLibrary.h"

typedef void(_STDCALL* VoidFunc)();


DynamicLinkLibrary* dll = nullptr;

extern "C" {

    _EXPORT void _STDCALL Init()
    {
        dll = new DynamicLinkLibrary();
        dll->Load("Base.dll");
    }

    _EXPORT void _STDCALL Terminate()
    {
        dll->Release();
    }

    _EXPORT void _STDCALL Print()
    {
        dll->GetProc<VoidFunc>("Print")();
    }

    _EXPORT void _STDCALL Inc()
    {
        dll->GetProc<VoidFunc>("Inc")();
    }

}