#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<WinSock2.h>
#include<string>
#include<vector>
#include<thread>
#include"Message.h"
#pragma comment(lib, "WS2_32.lib")//DLL

using namespace std;

int main()
{
	WSAData wasData;
	int Result = WSAStartup(MAKEWORD(2, 2), &wasData);
	if (Result < 0)
	{
		cout << "Winsock init Error. : " << GetLastError() << '\n';
		exit(-1);
	}


	Message m;

	connect(m.ServerSocket, (SOCKADDR*)&m.ServerAddr, sizeof(m.ServerAddr));

	thread t1{ &Message::GetSendMessage, &m};
	thread t2{ &Message::RecvMessage, &m };
	t1.join();
	t2.join();

	//closesocket(ServerSocket);
	closesocket(m.ServerSocket);
	WSACleanup();

	return 0;
}