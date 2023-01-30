//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#include<iostream>
//#include<WinSock2.h>
//#include<process.h>
//#include<Windows.h>
//
//#include<vector>
//#pragma comment(lib, "WS2_32.lib")
//#pragma comment(lib, "winmm.lib")
//using namespace std;
//
//int cnt = 0;
//HANDLE MutexHandle;
//CRITICAL_SECTION gold;
//unsigned WINAPI WorkThread(void* Arg)
//{
//	WaitForSingleObject(MutexHandle, INFINITE);
//	for (int i = 0; i < 10000; i++)
//	{
//		cnt++;
//	}
//	ReleaseMutex(MutexHandle);
//	
//	return 0;
//}
//unsigned WINAPI WorkThread2(void* Arg)
//{
//	WaitForSingleObject(MutexHandle, INFINITE);
//	for (int i = 0; i < 10000; i++)
//	{
//		cnt++;
//	}
//	ReleaseMutex(MutexHandle);
//
//	return 0;
//}
//
//
//
//int main()
//{
//	MutexHandle = CreateMutex(nullptr, false, nullptr);
//	InitializeCriticalSection(&gold);
//
//	int StartTime = timeGetTime();
//	HANDLE hThread[2];
//
//	hThread[0] = (HANDLE)_beginthreadex(nullptr, 0, WorkThread, 0, 0, 0);
//	hThread[1] = (HANDLE)_beginthreadex(nullptr, 0, WorkThread, 0, 0, 0);
//
//	cout << timeGetTime() - StartTime << '\n';
//
//	HANDLE hThread2[2];
//	StartTime = timeGetTime();
//	hThread2[0] = (HANDLE)_beginthreadex(nullptr, 0, WorkThread2, 0, 0, 0);
//	hThread2[1] = (HANDLE)_beginthreadex(nullptr, 0, WorkThread2, 0, 0, 0);
//	cout << timeGetTime() - StartTime << '\n';
//
//
//	WaitForMultipleObjects(2, hThread, true, INFINITE);
//
//	cout << cnt << '\n';
//
//	DeleteCriticalSection(&gold);
//	CloseHandle(MutexHandle);
//
//	
//
//	return 0;
//}