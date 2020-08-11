#include "DynamicLinkLibrary.h"

typedef void(_STDCALL* VoidFunc)();

int main()
{
	auto dll1 = new DynamicLinkLibrary();
	dll1->Load("Link1.dll");

	auto dll2 = new DynamicLinkLibrary();
	dll2->Load("Link2.dll");

	dll1->GetProc<VoidFunc>("Init")();
	dll2->GetProc<VoidFunc>("Init")();

	dll1->GetProc<VoidFunc>("Inc")();
	dll1->GetProc<VoidFunc>("Print")();

	dll2->GetProc<VoidFunc>("Inc")();
	dll2->GetProc<VoidFunc>("Print")();

	dll1->GetProc<VoidFunc>("Terminate")();
	dll2->GetProc<VoidFunc>("Terminate")();

	dll1->Release();
	dll2->Release();

	return 0;
}
