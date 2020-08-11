
#include "DynamicLinkLibrary.h"
#include <stdio.h>

int counter = 0;

extern "C" {

	_EXPORT void _STDCALL Print()
	{
		printf("%d\n", counter);
	}

	_EXPORT void _STDCALL Inc()
	{
		counter++;
	}

}