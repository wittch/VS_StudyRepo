#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "WS2_32.lib")

using namespace std;

//program - socket - 1.1.1.1:4949
//ip : 1.1.1.1 computer
//port : 4949 program

int main()
{
	WSAData WsaData;

	WSAStartup(MAKEWORD(2, 2), &WsaData);

	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN ServerSockAddr;
	ZeroMemory(&ServerSockAddr, sizeof(ServerSockAddr));
	ServerSockAddr.sin_family = PF_INET;
	ServerSockAddr.sin_addr.S_un.S_addr = inet_addr("172.16.2.104");
	ServerSockAddr.sin_port = htons(4949);

	connect(ServerSocket, (SOCKADDR*)&ServerSockAddr, sizeof(ServerSockAddr));


	while (true)
	{
		char Buffer[1024];
		ZeroMemory(&Buffer, sizeof(Buffer));
		cout << "Input Message : " << endl;
		cin >> Buffer;

		int SentLength = send(ServerSocket, Buffer, (int)strlen(Buffer), 0);
		if (SentLength == 0)
		{
			cout << "Disconnect." << endl;
			break;
		}
		else if (SentLength < 0)
		{
			cout << "error Disconnect. : " << GetLastError() << endl;
			break;
		}

		int RecvLength = recv(ServerSocket, Buffer, (int)sizeof(Buffer) - 1, 0);

		cout << "Server Send : " << Buffer << endl;
	}

	closesocket(ServerSocket);
	WSACleanup();

	return 0;
}