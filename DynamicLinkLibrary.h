
#pragma once

#include <atomic>
#include <string>

#ifdef _WIN32
#include <Windows.h>
#else
#include <dlfcn.h>
#include <cstddef>
#endif

#ifdef _WIN32
#define	_STDCALL	__stdcall
#else
#define	_STDCALL
#endif

#ifdef _WIN32
#define _EXPORT __declspec(dllexport)
#else
#define _EXPORT
#endif

inline std::string ConvertSharedObjectPath(std::string path)
{
#ifndef _WIN32
	path = "lib" + path;
#endif

#ifdef _WIN32
	path += ".dll";
#elif defined(__APPLE__)
	path += ".dylib";
#else
	path += ".so";
#endif
	return path;
}

/**
@brief	A class to controll DLL
*/
class DynamicLinkLibrary
{
private:
	mutable std::atomic<int32_t> reference_;

#if _WIN32
	HMODULE dll_;
#else
	void* dll_ = nullptr;
#endif

public:
	DynamicLinkLibrary();

	~DynamicLinkLibrary();

	void Reset();

	/**
		@brief load a dll
	*/
	bool Load(const char* path);

	/**
		@brief get a function pointer
	*/
	template <typename T> T GetProc(const char* name)
	{
#if _WIN32
		void* pProc = ::GetProcAddress(dll_, name);
#else
		void* pProc = dlsym(dll_, name);
#endif
		if (pProc == NULL)
		{
			return nullptr;
		}
		return (T)(pProc);
	}

	int AddRef();

	int GetRef();

	int Release();
};
