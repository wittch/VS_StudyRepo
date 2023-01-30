#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<WinSock2.h>
#include<map>
#include"MessagePacket.h"
#include"PlayerData.h"


#pragma comment(lib, "WS2_32.lib")

using namespace std;
map<SOCKET, PlayerData*> PlayerList;
CRITICAL_SECTION ServerCS;
char Data[18] = { 0, };


int main()
{

	WSAData wsaData;
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN ServerSocketAddr;
	memset(&ServerSocketAddr, 0, sizeof(SOCKADDR_IN));
	ServerSocketAddr.sin_family = PF_INET;
	ServerSocketAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	ServerSocketAddr.sin_port = htons(4949);

	bind(ServerSocket, (SOCKADDR*)&ServerSocketAddr, sizeof(ServerSocketAddr));

	listen(ServerSocket, 5);



	return 0;
}