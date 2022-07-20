#pragma once

#ifdef ENGINE_WINDOWS
	#ifdef BUILD_DLL
		#define ENGINE_API __declspec(dllexport)
	#else
		#define ENGINE_API __declspec(dllimport)
	#endif
#else
	#error Engine supports only windows.
#endif

#include <iostream>

#define BIT(x) (1 << x)