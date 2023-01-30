#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<WinSock2.h>
#pragma comment (lib, "WS2_32.lib")

using namespace std;
int main()
{
	WSAData wsaData;
	int Result = WSAStartup(MAKEWORD(2, 2), &wsaData); 

	if (Result <= 0)
	{
		cout << GetLastError() << '\n';
	}

	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN ServerAddr;
	memset(&ServerAddr, 0, sizeof(SOCKADDR_IN));

	ServerAddr.sin_family = PF_INET;
	ServerAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	ServerAddr.sin_port = htons(4949);

	connect(ServerSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));

	char Buffer[1024] = { 0, };
	while (1)
	{
		cout << ServerSocket;
		cin >> Buffer;
		send(ServerSocket, Buffer, sizeof(Buffer), 0);
		recv(ServerSocket, Buffer, sizeof(Buffer), 0);
		
		cout<<"Server : " << Buffer << '\n';
	}

	


	return 0;
}