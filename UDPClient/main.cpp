#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include<iostream>
#include<winsock2.h>

#pragma comment(lib, "WS2_32.lib")

using namespace std;

int main()
{
	WSAData wsaData;
	int Result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET ServerSocket = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN ServerSocketAddr;
	memset(&ServerSocketAddr, 0, sizeof(SOCKADDR_IN));
	ServerSocketAddr.sin_family = PF_INET;
	ServerSocketAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	ServerSocketAddr.sin_port = htons(4949);

	FILE* fp = fopen("123.jpg", "wb");
	bool running = true;

	char getfile[1024][1024];
	while (running)
	{
		char Buffer[1024] = { 0, };

		SOCKADDR_IN RemoteSockAddr;
		memset(&RemoteSockAddr, 0, sizeof(SOCKADDR_IN));
		int Remotesocketlength = sizeof(RemoteSockAddr);

		recvfrom(ServerSocket, Buffer, 1024, 0, (SOCKADDR*)&RemoteSockAddr, &Remotesocketlength);
		
		for (int i = 0; i < 1023; i++)
		{
			getfile[i][Buffer[1023]] = Buffer[i];
		}
		
	}
	fwrite(getfile[][i], sizeof(char), atoi(getfile[][]), fp);

	while (true) { 
		char Buffer[1024] = { 0, };
		cin >> Buffer;
		SOCKADDR_IN RemoteSockAddr;
		memset(&RemoteSockAddr, 0, sizeof(SOCKADDR_IN));
		int Remotesocketlength = sizeof(RemoteSockAddr);

		int sendlength = sendto(ServerSocket, Buffer, strlen(Buffer), 0, (SOCKADDR*)&ServerSocketAddr, sizeof(ServerSocketAddr));

		int recvLength = recvfrom(ServerSocket, Buffer, sizeof(Buffer), 0, (SOCKADDR*)&RemoteSockAddr, &Remotesocketlength);
		cout << Buffer<<'\n';
	}

	closesocket(ServerSocket);
	WSACleanup();

	return 0;
}

/*
* TPC
* STREAM
* 전화
*/

/*
* UDP
* 자료 패킹 DataGram
* 택배
*/