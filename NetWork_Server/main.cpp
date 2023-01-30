#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<WinSock2.h>
#include<string>

#pragma comment(lib, "WS2_32.lib")//DLL

using namespace std;

int main()
{
	WSAData wsaData;
	
	
	int Result = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (Result < 0)
	{
		cout << "Winsock init Error. : " << GetLastError() << '\n';
		exit(-1);
	}
	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN ServerSocketAddr;
	memset(&ServerSocketAddr, 0, sizeof(SOCKADDR_IN));

	ServerSocketAddr.sin_family = PF_INET;
	ServerSocketAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	ServerSocketAddr.sin_port = htons(4848);

	int status = bind(ServerSocket, (sockaddr*)&ServerSocketAddr, sizeof(ServerSocketAddr));

	status = listen(ServerSocket, 0);


	SOCKADDR_IN ClientSocketAddr;
	memset(&ClientSocketAddr, 0, sizeof(SOCKADDR_IN));
	int ClientAddrLength = sizeof(ClientSocketAddr);

	SOCKET ClientSocket = accept(ServerSocket, (sockaddr*)&ClientSocketAddr, &ClientAddrLength);
	
	if (ClientSocket == INVALID_SOCKET)
	{
		cout << "Error : " << GetLastError() << '\n';
		exit(-1);
	}
	while (1) {
		char Buffer[1024] = { 0, };

		int recvBytes = recv(ClientSocket, Buffer, 1024, 0);
		if (recvBytes <= 0)
		{
			cout << "Error : " << GetLastError() << '\n';
			exit(-1);
		}

		int sendBytes = send(ClientSocket, Buffer, 1024, 0);
		if (sendBytes > 0) {
			cout << "Server send complete." << endl;

		}
	}
	

	closesocket(ClientSocket);
	closesocket(ServerSocket);

	WSACleanup();


	return 0;
}