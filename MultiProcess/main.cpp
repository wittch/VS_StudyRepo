#include<iostream>
#include<Windows.h>
#include<process.h>

#pragma comment(lib,"Winmm.lib")

int Gold = 100;
CRITICAL_SECTION CS_Gold;

unsigned WINAPI Increase(void* Arg)
{
		EnterCriticalSection(&CS_Gold);
	for (int i = 0; i < 100000; i++)
	{
		Gold++;
	}
		LeaveCriticalSection(&CS_Gold);

	return 0;
}

unsigned WINAPI Decrease(void* Arg)
{
		EnterCriticalSection(&CS_Gold);
	for (int i = 0; i < 100000; i++)
	{
		Gold--;
	}
		LeaveCriticalSection(&CS_Gold);
	return 0;
}

int main()
{

	DWORD StartTime = timeGetTime();

	InitializeCriticalSection(&CS_Gold);

	unsigned int ThreadID = 0;

	HANDLE ThreadHandle[2];
	ThreadHandle[0] = (HANDLE)_beginthreadex(nullptr, 0, Increase, nullptr, 0, &ThreadID);
	ThreadHandle[1] = (HANDLE)_beginthreadex(nullptr, 0, Decrease, nullptr, 0, &ThreadID);
	
	WaitForMultipleObjects(2, ThreadHandle, true, INFINITE);
	 
	std::cout << (timeGetTime() - StartTime) << '\n';
	

	DeleteCriticalSection(&CS_Gold);

	return 0;
}